#include "NetworkController.h"
#include "File.h"

bool NetworkController::readData() {
    File file;
    stations = file.readStations();
    segments = file.readNetwork();
    if(!stations.empty() && !segments.empty())
        return true;
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