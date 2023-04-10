#pragma once


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
    Network reducedNetwork;
    Station findStation(Vertex* v);
    static bool checkIfExists(const vector<Municipality>& munis, const string &name);
    static bool checkIfExists(const vector<District>& dists, const string &name);
public:
    bool readData();
    Station findStation(const string& name);
    Segment findSegment(const string& stationA, const string& stationB);
    double maxTrainsBetweenStations(const string& source, const string& dest);
    double maxTrainsBetweenStationsMinCost(const string& source, const string& dest);
    double maxTrainsBetweenStationsReduced(const string& source, const string& dest);
    vector<string> pairWithMostTrains();
    vector<Municipality> topkMunicipalities();
    vector<District> topkDistricts();
    double maxTrainsArriveStation(const string &t);
    bool reduceNetwork(const string& source, const string& dest);
    vector<Station> topkAffectedStations();
};
