#include "File.h"
#include "iostream"
#include <fstream>
#include <sstream>
using namespace std;

vector<Station> File::readStations() {
    vector<Station> stations;
    string header;
    string name, district, municipality, township, line;

    ifstream file("dataset/stations.csv");
    if(!file.is_open()){
        cout << "File 'stations' not opened" << endl;

    }
    getline(file, header);

    while(!file.eof()){
        getline(file, name, ',');
        getline(file, district, ',');
        getline(file, municipality, ',');
        getline(file, township, ',');
        getline(file, line);
        stations.emplace_back(name, district, municipality, township, line);
    }
    file.close();
    return stations;
}

vector<Segment> File::readNetwork() {
    vector<Segment> network;
    string header;
    string stationA, stationB, cap, service;
    int capacity;

    ifstream file("dataset/network.csv");
    if(!file.is_open()){
        cout << "File 'network' not opened" << endl;
    }
    getline(file, header);

    while(!file.eof()){
        getline(file, stationA, ',');
        getline(file, stationB, ',');
        getline(file, cap, ',');
        stringstream s1(cap); s1 >> capacity;
        getline(file, service);
        network.emplace_back(stationA, stationB, capacity, service);
    }
    file.close();
    return network;
}