#include "Segment.h"

Segment::Segment() {
    this->stationA = "default";
    this->stationB = "default";
    this->capacity = 0;
    this->service = "default";
}

Segment::Segment(string stationA, string stationB, int capacity, string service) {
    this->stationA = stationA;
    this->stationB = stationB;
    this->capacity = capacity;
    this->service = service;
}

string Segment::getStationA() const { return this->stationA; }

string Segment::getStationB() const { return this->stationB; }

int Segment::getCapacity() const { return this->capacity; }

string Segment::getService() const { return this->service; }