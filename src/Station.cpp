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