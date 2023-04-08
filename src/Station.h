#ifndef STATION_H
#define STATION_H

#include "iostream"
#include "vector"

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


class Municipality {
    string name;
    double flow;
public:
    Municipality(string name);
    string getName();
    double getFlow() const;
    void setFlow(double flow);
};

class District {
    string name;
    double flow;
public:
    District(string name);
    string getName();
    double getFlow() const;
    void setFlow(double flow);
};

#endif //STATION_H
