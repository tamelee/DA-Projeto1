#ifndef STATION_H
#define STATION_H

#include "iostream"

using namespace std;

class Station {
    string name;
    string district;
    string municipality;
    string township;
    string line;
public:
    Station();
    Station(string name, string district, string municipality, string township, string line);
    string getName();
    string getDistrict();
    string getMunicipality();
    string getTownship();
    string getLine();
};


#endif //STATION_H
