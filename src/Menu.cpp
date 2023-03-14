#include "Menu.h"

void Menu::appMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*        Railway                         *" << endl;
    cout << "*          Network                       *" << endl;
    cout << "*                                        *" << endl;
    cout << "*     1) MANAGE DATA                     *" << endl;
    cout << "*     2) BASIC SERVICE METRICS           *" << endl;
    cout << "*     3) OPERATION COST OPTIMIZATION     *" << endl;
    cout << "*     4) RELIABILITY AND SENSITIVITY     *" << endl;
    cout << "*     0) EXIT                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: exit(0);
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3 && option != 4);
}