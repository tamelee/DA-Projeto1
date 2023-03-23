#include "Menu.h"
#include "Station.h"
#include "Segment.h"

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
    cout << "*     2) VIEW STATION INFORMATION        *" << endl;
    cout << "*     3) VIEW NETWORK SEGMENT            *" << endl;
    cout << "*        INFORMATION                     *" << endl;
    cout << "*                               0) BACK  *" << endl;
    cout << "******************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: {
                if(controller.readData())
                    cout << "DATA SET OPENED SUCCESSFULLY" << endl;
                else
                    cout << "DATA SET CANNOT BE OPENED" << endl;
                dataMenu();
                break;
            }
            case 2: viewStation(); break;
            case 3: viewSegment(); break;
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

void Menu::viewStation() {
    cout << "Station's Name: ";
    string name;
    getline(cin >> ws, name);
    Station stat = controller.findStation(name);
    cout << "*******************************************************************" << endl;
    cout << "                        STATION INFORMATION                        " << endl;
    cout << endl;
    cout << "\tNAME:\t\t\t" << stat.getName() << endl;
    cout << "\tDISTRICT:\t\t" << stat.getDistrict() << endl;
    cout << "\tMUNICIPALITY:\t" << stat.getMunicipality() << endl;
    cout << "\tTOWNSHIP:\t\t" << stat.getTownship() << endl;
    cout << "\tLINE:\t\t\t" << stat.getLine() << endl;
    cout << endl;
    cout << "                                                         0) BACK   " << endl;
    cout << "*******************************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        if(option == 0)
            dataMenu();
        else
            cout << "Invalid option, please try again: ";
    } while(option != 0);
}

void Menu::viewSegment() {
    cout << "Station A: ";
    string stationA; getline(cin >> ws, stationA);
    cout << "Station B: ";
    string stationB; getline(cin >> ws, stationB);
    Segment seg = controller.findSegment(stationA, stationB);
    cout << "*******************************************************************" << endl;
    cout << "                        SEGMENT INFORMATION                        " << endl;
    cout << endl;
    cout << "\tSTATION A:\t\t" << seg.getStationA() << endl;
    cout << "\tSTATION B:\t\t" << seg.getStationB() << endl;
    cout << "\tCAPACITY:\t\t" << seg.getCapacity() << endl;
    cout << "\tSERVICE:\t\t" << seg.getService() << endl;
    cout << endl;
    cout << "                                                         0) BACK   " << endl;
    cout << "*******************************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        if(option == 0)
            dataMenu();
        else
            cout << "Invalid option, please try again: ";
    } while(option != 0);
}