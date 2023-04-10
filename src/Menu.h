#pragma once

#include "iostream"
#include "NetworkController.h"

using namespace std;

class Menu {
    NetworkController controller;
public:
    void mainMenu();
protected:
    void dataMenu();
    void bsmMenu();
    void ocoMenu();
    void rasMenu();
    void reliAndSensiMenu();
    void removeSegment();
    void viewStation();
    void viewSegment();
    void viewMaxTrainsBetweenStations();
    void viewPairWithMostTrains();
    void municipalitiesOrDistricts();
    void viewTopkMunicipalities();
    void viewTopkDistricts();
    void viewMaxTrainsArriveStation();
    void viewMaxTrainsBetweenStationsMinCost();
    void viewTopkAffectedStations();
    void viewMaxTrainsBetweenStationsReduced();
    static int askTopk();
    void goBackMenu();
};

