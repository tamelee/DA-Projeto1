#ifndef MENU_H
#define MENU_H

#include "iostream"
#include "NetworkController.h"

using namespace std;

class Menu {
    NetworkController controller;
public:
    void mainMenu();
    void dataMenu();
    void bsmMenu();
    void ocoMenu();
    void rasMenu();
    void viewStation();
    void viewSegment();
};


#endif //MENU_H
