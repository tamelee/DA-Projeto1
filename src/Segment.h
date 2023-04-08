#ifndef SEGMENT_H
#define SEGMENT_H

#include "iostream"

using namespace std;

class Segment {
    string stationA;
    string stationB;
    int capacity;
    string service;
public:
    Segment();
    Segment(string stationA, string stationB, int capacity, string service);
    string getStationA() const;
    string getStationB() const;
    int getCapacity() const;
    string getService() const;
};


#endif //SEGMENT_H
