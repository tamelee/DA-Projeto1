#include "Station.h"

Station::Station() {
    this->name = "default";
    this->district = "default";
    this->municipality = "default";
    this->township = "default";
    this->line = "default";
}

Station::Station(string name, string district, string municipality, string township, string line) {
    this->name = name;
    this->district = district;
    this->municipality = municipality;
    this->township = township;
    this->line = line;
}

string Station::getName() {
    return this->name;
}

string Station::getDistrict() {
    return this->district;
}

string Station::getMunicipality() {
    return this->municipality;
}

string Station::getTownship() {
    return this->township;
}

string Station::getLine() {
    return this->line;
}

//****** Municipality *******//
Municipality::Municipality(string name) {this->name = std::move(name); flow = 0;}

string Municipality::getName() { return this->name; }

double Municipality::getFlow() const { return this->flow; }

void Municipality::setFlow(double flow) { this->flow = flow;}

//****** District *******//
District::District(string name) {this->name = std::move(name); flow = 0;}

string District::getName() { return this->name; }

double District::getFlow() const { return this->flow; }

void District::setFlow(double flow) { this->flow = flow;}
