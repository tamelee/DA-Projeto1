#ifndef FILE_H
#define FILE_H

#include "Station.h"
#include "Segment.h"
#include "vector"

class File {
public:
    vector<Station> readStations();
    vector<Segment> readNetwork();
};


#endif //FILE_H
