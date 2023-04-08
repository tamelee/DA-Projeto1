#include "NetworkController.h"
#include "File.h"

bool NetworkController::readData() {
    File file;
    stations = file.readStations();
    segments = file.readNetwork();
    if(!stations.empty() && !segments.empty()){
        network.createNetwork(stations, segments);
        return true;
    }
    return false;
}

Station NetworkController::findStation(const string& name) {
    Station stat;
    for(auto & station : stations){
        if(station.getName() == name)
            stat = station;
    }
    return stat;
}

Segment NetworkController::findSegment(const string& stationA, const string& stationB) {
    Segment seg;
    for(auto& segment: segments){
        if(segment.getStationA() == stationA && segment.getStationB() == stationB)
            seg = segment;
    }
    return seg;
}

double NetworkController::maxTrainsBetweenStations(const string &source, const string &dest) {
    return network.maximum_flow(source, dest);
}

vector<string> NetworkController::pairWithMostTrains() {
    double maxFlow = 0;
    double flow;
    string source;
    string target;
    vector<string> pair;

    for(auto s: network.getVertexSet()){
        for(auto t: network.getVertexSet()){
            if(s->getName() != t->getName()){
                flow = network.maximum_flow(s->getName(), t->getName());
                if(flow > maxFlow){
                    maxFlow = flow;
                    source = s->getName();
                    target = t->getName();
                }
            }
        }
    }

    /*
    for(auto v: network.getVertexSet()){
        v->setVisited(false);
    }

    for (auto v : network.getVertexSet()) {
        if (!v->isVisited()) {
            // v is the start of a new connected component
            v->setVisited(true);
            vector<Vertex*> component = {v};
            queue<Vertex*> q;
            q.push(v);

            // Perform BFS to find all vertices in the connected component
            while (!q.empty()) {
                Vertex* u = q.front();
                q.pop();
                for (auto edge : u->getAdj()) {
                    Vertex* w = edge->getDest();
                    if (!w->isVisited()) {
                        w->setVisited(true);
                        component.push_back(w);
                        q.push(w);
                    }
                }
            }

            // Compute the maximum flow between all pairs of vertices within the connected component
            double maxFlowComponent = 0;
            string sourceComponent, targetComponent;
            for (auto s : component) {
                for (auto t : component) {
                    if (s != t) {
                        flow = network.maximum_flow(s->getName(), t->getName());
                        if (flow > maxFlowComponent) {
                            maxFlowComponent = flow;
                            sourceComponent = s->getName();
                            targetComponent = t->getName();
                        }
                    }
                }
            }

            // Update the maximum flow and source/target vertices if the maximum flow within the component is greater
            if (maxFlowComponent > maxFlow) {
                maxFlow = maxFlowComponent;
                source = sourceComponent;
                target = targetComponent;
            }
        }
    }
    */


    pair.push_back(source);
    pair.push_back(target);
    return pair;
}

vector<Municipality> NetworkController::topkMunicipalities() {
    vector<Municipality> muni;
    double flow;

    for(auto s: stations){
        if(muni.empty())
            muni.emplace_back(s.getMunicipality());
        else{
            if(!checkIfExists(muni, s.getMunicipality()))
                muni.emplace_back(s.getMunicipality());
        }
    }

    for(auto s: stations){
        for(auto t: stations){
            if(s.getName() != t.getName()){
                flow = network.maximum_flow(s.getName(), t.getName());
                muni[0].setFlow(flow);
                for(auto m: muni){
                    if(s.getMunicipality() == m.getName() || t.getMunicipality() == m.getName())
                        m.setFlow(flow);
                }
            }
        }
    }
    return muni;
}

double NetworkController::maxTrainsArriveStation() {

}

bool NetworkController::checkIfExists(vector<Municipality> munis, const string &name) {
    for(auto m: munis){
        if(m.getName() == name)
            return true;
    }
    return false;
}