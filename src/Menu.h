#ifndef MENU_H
#define MENU_H

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
    void viewStation();
    void viewSegment();
    void viewMaxTrainsBetweenStations();
    void viewPairWithMostTrains();
    void viewTopkMunicipalities();
    void viewMaxTrainsArriveStation();
};


#endif //MENU_H
