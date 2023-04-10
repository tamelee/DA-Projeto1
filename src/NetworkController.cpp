#include "NetworkController.h"
#include "File.h"

/**
 * Read data from file.
 * @return true if reads file successfully otherwise false;
 */
bool NetworkController::readData() {
    File file;
    stations = file.readStations();
    segments = file.readNetwork();
    if(!stations.empty() && !segments.empty()){
        network.createNetwork(stations, segments);
        reducedNetwork = network;
        return true;
    }
    return false;
}

/**
 * Check if a station exists. Time complexity: O(n).
 * @param name name of the station to be found;
 * @return station object;
 */
Station NetworkController::findStation(const string& name) {
    Station stat;
    for(auto & station : stations){
        if(station.getName() == name)
            stat = station;
    }
    return stat;
}

/**
 * Check if a segment exists. Time complexity: O(n).
 * @param stationA name of the source station of the segment;
 * @param stationB name of the target station of the segment;
 * @return segment object;
 */
Segment NetworkController::findSegment(const string& stationA, const string& stationB) {
    Segment seg;
    for(auto& segment: segments){
        if(segment.getStationA() == stationA && segment.getStationB() == stationB)
            seg = segment;
    }
    return seg;
}

/**
 * Finds the maximum flow between two given stations. Time complexity: O(V * E^2).
 * @param source source node;
 * @param dest target node;
 * @return maximum flow;
 */
double NetworkController::maxTrainsBetweenStations(const string &source, const string &dest) {
    return network.maximum_flow(source, dest);
}

/**
 * Finds the pair of stations with the highest maximum flow.
 * Time complexity: O(V*E)
 * @return vector with the pair of stations;
 */
vector<string> NetworkController::pairWithMostTrains() {
    double maxFlow = 0;
    double flow;
    string source;
    string target;
    vector<string> pair;

    for(auto s: network.getVertexSet()){
        if(s->getAdj().empty()) continue;
        for(auto t: s->getAdj()){
            flow = network.maximum_flow(s->getName(), t->getDest()->getName());
            if(flow > maxFlow){
                maxFlow = flow;
                source = s->getName();
                target = t->getDest()->getName();
            }
        }
    }

    pair.push_back(source);
    pair.push_back(target);
    return pair;
}

/**
 * Finds the top-k municipalities. Time complexity: O(n^2).
 * @return vector with municipalities sorted by total flow;
 */
vector<Municipality> NetworkController::topkMunicipalities() {
    vector<Municipality> munis;
    double aux;
    double sum = 0;

    for(auto s: stations){
        if(munis.empty())
            munis.emplace_back(s.getMunicipality());
        else{
            if(!checkIfExists(munis, s.getMunicipality()))
                munis.emplace_back(s.getMunicipality());
        }
    }


    for(auto& m: munis){
        for(auto& s: stations){
            if(s.getMunicipality() == m.getName()){
                auto v = network.findVertex(s.getName());
                for(auto& e: v->getAdj()){
                    Station station = findStation(e->getDest());
                    if(station.getMunicipality() == m.getName()) {
                        aux = e->getWeight();
                        sum += aux;
                    }
                }
            }
        }
        m.setFlow(sum);
        sum = 0;
    }

    sort(munis.begin(), munis.end(), [](const Municipality& m1, const Municipality& m2)->bool{
        return m1.getFlow() > m2.getFlow();
    });

    return munis;
}

/**
 * Finds the top-k districts. Time complexity: O(n^2).
 * @return vector with districts sorted by total flow;
 */
vector<District> NetworkController::topkDistricts() {
    vector<District> distrs;
    double aux;
    double sum = 0;

    for(auto s: stations){
        if(distrs.empty())
            distrs.emplace_back(s.getDistrict());
        else{
            if(!checkIfExists(distrs, s.getDistrict()))
                distrs.emplace_back(s.getDistrict());
        }
    }


    for(auto& d: distrs){
        for(auto& s: stations){
            if(s.getDistrict() == d.getName()){
                auto v = network.findVertex(s.getName());
                for(auto& e: v->getAdj()){
                    Station station = findStation(e->getDest());
                    if(station.getDistrict() == d.getName()) {
                        aux = e->getWeight();
                        sum += aux;
                    }
                }
            }
        }
        d.setFlow(sum);
        sum = 0;
    }

    sort(distrs.begin(), distrs.end(), [](const District& d1, const District& d2)->bool{
        return d1.getFlow() > d2.getFlow();
    });
    return distrs;
}

/**
 * Calculates the maximum flow from all possible sources to a specific station;
 * Time complexity: O(V^2*E^2).
 * @param t target node;
 * @return maximum flow
 */
double NetworkController::maxTrainsArriveStation(const string &t) {
    double maxflow = 0;
    double flow;

    for(auto s: network.getVertexSet()){
        if(s->getName() != t)
            flow = network.maximum_flow(s->getName(), t);
        if(flow > maxflow)
            maxflow = flow;
    }

    return maxflow;
}

double NetworkController::maxTrainsBetweenStationsMinCost(const string &source, const string &dest) {
    int maxFlow = 0;

    return 0;
}

/**
 * remove segments(edges) from network graph. Time complexity: O(E).
 * @param source source station of the segment;
 * @param dest destination station of the segment;
 * @return true if segment is removed otherwise false;
 */
bool NetworkController::reduceNetwork(const string& source, const string& dest) {
    auto s = reducedNetwork.findVertex(source);
    return s->removeEdge(dest);
}

/**
 * Finds the maximum flow between two given stations in a reduced network.
 * Time complexity: O(V * E^2).
 * @param source source node;
 * @param dest target node;
 * @return maximum flow;
 */
double NetworkController::maxTrainsBetweenStationsReduced(const string &source, const string &dest) {
    return reducedNetwork.maximum_flow(source, dest);
}

vector<Station> NetworkController::topkAffectedStations() {
    vector<Station> stats;

    network.edmondsKarp("Entroncamento", "Lisboa Oriente");
    for(auto& v: network.getVertexSet()){
        for(auto& e: v->getAdj()){
            if(e->getFlow() != 0)
                cout << v->getName() << " -> " << e->getFlow() << " <- " << e->getDest()->getName() << endl;
        }
    }

    cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;

    reducedNetwork.edmondsKarp("Entroncamento", "Lisboa Oriente");
    for(auto& v: reducedNetwork.getVertexSet()){
        for(auto& e: v->getAdj()){
            if(e->getFlow() != 0)
                cout << v->getName() << " -> " << e->getFlow() << " <- " << e->getDest()->getName() << endl;
        }
    }

    return stats;
}

/**
 * Checks if a municipality it's already inserted in the vector.
 * @param munis vector with municipalities objects;
 * @param name name of a municipality;
 * @return true if found otherwise false;
 */
bool NetworkController::checkIfExists(const vector<Municipality>& munis, const string &name) {
    for(auto m: munis){
        if(m.getName() == name)
            return true;
    }
    return false;
}

/**
 * Checks if a district is already inserted in the vector.
 * @param distrs vector with districts objects;
 * @param name name of a district;
 * @return true if found otherwise false;
 */
bool NetworkController::checkIfExists(const vector<District>& distrs, const string &name) {
    for(auto d: distrs){
        if(d.getName() == name)
            return true;
    }
    return false;
}

/**
 * Search for a station. Time complexity: O(n).
 * @param v vertex of the station to be found;
 * @return station object;
 */
Station NetworkController::findStation(Vertex* v){
    Station station;
    for(auto& s: stations) {
        if (s.getName() == v->getName())
            station = s;
    }
    return station;
}
