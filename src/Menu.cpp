#include "Menu.h"

/**
 * funcao para imprimir o menu principal do programa
 */
void Menu::mainMenu() {
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
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: dataMenu(); break;
            case 2: bsmMenu(); break;
            case 3: ocoMenu(); break;
            case 4: rasMenu(); break;
            case 0: exit(0);
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3 && option != 4);
}

void Menu::dataMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*     1) READ DATA SET                   *" << endl;
    cout << "*     2) VIEW STATIONS                   *" << endl;
    cout << "*     3) VIEW NETWORK SEGMENTS           *" << endl;
    cout << "*                                        *" << endl;
    cout << "*                               0) BACK  *" << endl;
    cout << "******************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3);
}

void Menu::bsmMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*     1) T2.1                            *" << endl;
    cout << "*     2) T2.2                            *" << endl;
    cout << "*     3) T2.3                            *" << endl;
    cout << "*     4) T2.4                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "*                               0) BACK  *" << endl;
    cout << "******************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3 && option != 4);
}

void Menu::ocoMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*                                        *" << endl;
    cout << "*     1) T3.1                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "*                               0) BACK  *" << endl;
    cout << "******************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1);
}

void Menu::rasMenu() {
    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*                                        *" << endl;
    cout << "*     1) T4.1                            *" << endl;
    cout << "*     2) T4.2                            *" << endl;
    cout << "*                                        *" << endl;
    cout << "*                               0) BACK  *" << endl;
    cout << "******************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 2: break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2);
}