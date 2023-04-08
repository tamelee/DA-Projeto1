#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H


#include "vector"
#include "Station.h"
#include "Segment.h"
#include "Network.h"
#include "map"

class NetworkController {
    vector<Station> stations;
    vector<Segment> segments;
    Network network;
protected:
    static bool checkIfExists(vector<Municipality> munis, const string &name);
    bool checkIfExists(vector<District> dists, const string &name);
public:
    bool readData();
    Station findStation(const string& name);
    Segment findSegment(const string& stationA, const string& stationB);
    double maxTrainsBetweenStations(const string& source, const string& dest);
    vector<string> pairWithMostTrains();
    vector<Municipality> topkMunicipalities();
    double maxTrainsArriveStation();
};


#endif //NETWORKCONTROLLER_H
