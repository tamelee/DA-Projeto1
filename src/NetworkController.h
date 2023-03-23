#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H


#include "vector"
#include "Station.h"
#include "Segment.h"

class NetworkController {
    vector<Station> stations;
    vector<Segment> segments;
public:
    bool readData();
    Station findStation(const string& name);
    Segment findSegment(const string& stationA, const string& stationB);
};


#endif //NETWORKCONTROLLER_H
