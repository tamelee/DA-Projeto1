#include "Menu.h"
#include "Station.h"
#include "Segment.h"
#include <cstdlib>

/**
 * Prints the main menu of the program.
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

/**
 * Prints menu to read and verify data.
 */
void Menu::dataMenu() {
    cout << "******************************************" << endl;
    cout << "*  manage data                           *" << endl;
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
                mainMenu();
                break;
            }
            case 2: viewStation(); break;
            case 3: viewSegment(); break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3);
}

/**
 * Prints the Basic Service Metrics menu.
 */
void Menu::bsmMenu() {
    cout << "******************************************************************" << endl;
    cout << "*  basic service metrics                                         *" << endl;
    cout << "*                                                                *" << endl;
    cout << "*     1) VISUALIZE THE MAXIMUM NUMBER OF TRAINS THAT CAN         *" << endl;
    cout << "*        SIMULTANEOUSLY TRAVEL BETWEEN TWO SPECIFIC STATIONS     *" << endl;
    cout << "*     2) VISUALIZE WHICH PAIR OF STATIONS REQUIRE THE MOST       *" << endl;
    cout << "*        AMOUNT OF TRAINS                                        *" << endl;
    cout << "*     3) REPORT OF THE TOP-K MUNICIPALITIES AND DISTRICTS        *" << endl;
    cout << "*        TO ASSIGN LARGER BUDGETS                                *" << endl;
    cout << "*     4) REPORT OF THE MAXIMUM NUMBER OF TRAINS THAT CAN         *" << endl;
    cout << "*        SIMULTANEOUSLY ARRIVE AT A GIVEN STATION                *" << endl;
    cout << "*                                                                *" << endl;
    cout << "*                                                       0) BACK  *" << endl;
    cout << "******************************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: viewMaxTrainsBetweenStations(); break;
            case 2: viewPairWithMostTrains(); break;
            case 3: municipalitiesOrDistricts(); break;
            case 4: viewMaxTrainsArriveStation(); break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2 && option != 3 && option != 4);
}

/**
 * Prints the Operation Cost Optimization menu.
 */
void Menu::ocoMenu() {
    cout << "********************************************************" << endl;
    cout << "*  operation cost optimization                         *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     1) MAXIMUM AMOUNT OF TRAINS THAT CAN             *" << endl;
    cout << "*        SIMULTANEOUSLY TRAVEL BETWEEN TWO             *" << endl;
    cout << "*        SPECIFIC STATIONS WITH MINIMUM COST           *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*                                             0) BACK  *" << endl;
    cout << "********************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: viewMaxTrainsBetweenStationsMinCost(); break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1);
}

/**
 * Prints the Reliability and Sensitivity menu.
 */
void Menu::rasMenu() {
    cout << "********************************************************" << endl;
    cout << "*  reliability and sensitivity                         *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*     1) DISCONNECT SEGMENTS TO MAKE PERIODIC          *" << endl;
    cout << "*        MAINTENANCE AND OCCASIONAL REPAIRS            *" << endl;
    cout << "*                                                      *" << endl;
    cout << "*                                             0) BACK  *" << endl;
    cout << "********************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: removeSegment(); break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1);
}

/**
 * Prints the second part of the Reliability and Sensitivity menu.
 */
void Menu::reliAndSensiMenu() {
    cout << "****************************************************************" << endl;
    cout << "*  reliability and sensitivity                                 *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*     1) MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY      *" << endl;
    cout << "*        TRAVEL BETWEEN TWO SPECIFIC STATIONS                  *" << endl;
    cout << "*        IN A NETWORK OF REDUCED CONNECTIVITY                  *" << endl;
    cout << "*     2) REPORT OF THE TOP-K MOST AFFECTED                     *" << endl;
    cout << "*        STATIONS BY EACH SEGMENT FAILURE                      *" << endl;
    cout << "*                                                              *" << endl;
    cout << "*                                                     0) BACK  *" << endl;
    cout << "****************************************************************" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: viewMaxTrainsBetweenStationsReduced(); break;
            case 2: viewTopkAffectedStations(); break;
            case 0: mainMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    } while(option != 0 && option != 1 && option != 2);
}

/**
 * Prints information of a given station.
 */
void Menu::viewStation() {
    cout << "Station's name: ";
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
    goBackMenu();
}

/**
 * Prints information about a given segment.
 */
void Menu::viewSegment() {
    cout << "Departure station: ";
    string stationA; getline(cin >> ws, stationA);
    cout << "Arrival station: ";
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
    goBackMenu();
}

/**
 * Prints the maximum number of trains that can simultaneously travel
 * between two specific stations.
 */
void Menu::viewMaxTrainsBetweenStations() {
    int option;
    cout << "Departure station: ";
    string source; getline(cin >> ws, source);
    cout << "Arrival station: ";
    string dest; getline(cin >> ws, dest);
    double maxFlow = controller.maxTrainsBetweenStations(source, dest);
    if (maxFlow == -1) {
        cout << "INVALID DEPARTURE AND/OR ARRIVAL STATION  " << endl;
        cout << "1) TRY AGAIN                     0) BACK  " << endl;
        cout << "Option: ";
        do {
            cin >> option;
            switch(option) {
                case 1: viewMaxTrainsBetweenStations(); break;
                case 0: bsmMenu(); break;
                default: cout << "Invalid option, please try again: ";
            }
        }while(option != 1 && option != 0);
    } else {
        cout << "********************************************************" << endl;
        cout << "   MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY     " << endl;
        cout << "        TRAVEL BETWEEN TWO SPECIFIC STATIONS" << endl;
        cout << endl;
        cout << "  DEPARTURE STATION: " << source << endl;
        cout << "  ARRIVAL STATION: " << dest << endl;
        cout << "  NUMBER OF TRAINS = " << maxFlow << endl;
        cout << "                                               0) BACK  " << endl;
        cout << "********************************************************" << endl;
        cout << "Option: ";
        goBackMenu();
    }
}

/**
 * Prints the pair of stations that require the most amount of trains.
 */
void Menu::viewPairWithMostTrains() {
    vector<string> pair = controller.pairWithMostTrains();

    cout << "****************************************************" << endl;
    cout << "           PAIR OF STATIONS THAT REQUIRE           "<< endl;
    cout << "             THE MOST AMOUNT OF TRAINS             "<< endl;
    cout << endl;
    cout << " PAIR: " << pair.front() << " - "<< pair.back() << endl;
    cout << endl;
    cout << "                                           0) BACK  " << endl;
    cout << "****************************************************" << endl;
    cout << "Option: ";
    goBackMenu();
}

/**
 * Prints the menu for the user to choose the top-k of municipalities or districs.
 */
void Menu::municipalitiesOrDistricts() {
    cout << "********************************************" << endl;
    cout << "  1) MUNICIPALITIES" << endl;
    cout << "  2) DISTRICTS" << endl;
    cout << "                                     0) BACK" << endl;
    cout << "********************************************" << endl;
    cout << "Option: ";
    int option;
    do {
        cin >> option;
        switch(option) {
            case 1: viewTopkMunicipalities(); break;
            case 2: viewTopkDistricts(); break;
            case 0: bsmMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    }while(option != 1 && option != 2 && option != 0);
}

/**
 * Prints the top-k municipalities to assign larger budgets chosen by the user.
 */
void Menu::viewTopkMunicipalities() {
    vector<Municipality> munis = controller.topkMunicipalities();
    int k = askTopk();
    int i = 0;
    bool check = false;
    cout << "***********************************************************" << endl;
    cout << "       TOP-K MUNICIPALITIES TO ASSIGN LARGER BUDGETS       " << endl;
    cout << endl;
    while(i < k && i < munis.size()){
        cout << " " << i+1 << "º- " << munis[i].getName() << " - " << munis[i].getFlow() << endl;
        i++;
        if(i == k){
            while (munis[i-1].getFlow() == munis[i].getFlow()){
                check = true;
                cout << " *" << munis[i].getName() << " - " << munis[i].getFlow() << endl;
                i++;
            }
            if(check) cout << "  *additional municipalities for having the same value" << endl;
        }
    }
    cout << "                                                  0) BACK  " << endl;
    cout << "***********************************************************" << endl;
    cout << "Option: ";
    goBackMenu();
}

/**
 * Prints the top-k districts to assign larger budgets chosen by the user.
 */
void Menu::viewTopkDistricts() {
    vector<District> distrs = controller.topkDistricts();
    int k = askTopk();
    int i = 0;
    bool check = false;
    cout << "***********************************************************" << endl;
    cout << "        TOP-K DISTRICTS TO ASSIGN LARGER BUDGETS       " << endl;
    cout << endl;
    while(i < k && i < distrs.size()){
        cout << " " << i+1 << "º- " << distrs[i].getName() << " - " << distrs[i].getFlow() << endl;
        i++;
        if(i == k){
            while (distrs[i-1].getFlow() == distrs[i].getFlow()){
                check = true;
                cout << " *" << distrs[i].getName() << " - " << distrs[i].getFlow() << endl;
                i++;
            }
            if(check) cout << "  *additional municipalities for having the same value" << endl;
        }
    }
    cout << "                                                  0) BACK  " << endl;
    cout << "***********************************************************" << endl;
    cout << "Option: ";
    goBackMenu();
}

/**
 * Prints the maximum number of trains that can simultaneously arrive
 * at a given station.
 */
void Menu::viewMaxTrainsArriveStation(){
    cout << "Station: ";
    string station;
    getline(cin >> ws, station);
    double flow = controller.maxTrainsArriveStation(station);
    cout << "********************************************************" << endl;
    cout << "   MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY     " << endl;
    cout << "              ARRIVE AT A GIVEN STATION" << endl;
    cout << endl;
    cout << "  STATION: " << station << endl;
    cout << "  NUMBER OF TRAINS = " << flow << endl;
    cout << "                                               0) BACK  " << endl;
    cout << "********************************************************" << endl;
    cout << "Option: ";
    goBackMenu();
}

/**
 * Prints the maximum number of trains that can simultaneously travel
 * between two specific stations with minimum cost.
 */
void Menu::viewMaxTrainsBetweenStationsMinCost() {

}

/**
 * Menu for the user to remove k segments of the network.
 */
void Menu::removeSegment() {
    cout << "ENTER THE SEGMENT YOU WANT TO TURN UNAVAILABLE." << endl;
    cout << "Departure station: ";
    string stationA; getline(cin >> ws, stationA);
    cout << "Arrival station: ";
    string stationB; getline(cin >> ws, stationB);
    cout << endl;
    if(controller.reduceNetwork(stationA, stationB))
        cout << "SEGMENT UNAVAILABLE SUCCESSFULLY!" << endl;
    else
        cout << "FAILED OPERATION!" << endl;
    cout << "Do you want to do it again? (1-> Yes || 0-> No)" << endl;
    cout << "Option: ";
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: cout << endl; removeSegment(); break;
            case 0: cout << endl; reliAndSensiMenu(); break;
            default: cout << "Invalid option, please try again: ";
        }
    }while(option != 1 && option != 0);
}

/**
 * Prints the maximum number of trains that can simultaneously travel
 * between two specific stations with reduced network connectivity.
 */
void Menu::viewMaxTrainsBetweenStationsReduced() {
    int option;
    cout << "Departure station: ";
    string source; getline(cin >> ws, source);
    cout << "Arrival station: ";
    string dest; getline(cin >> ws, dest);
    double maxFlow = controller.maxTrainsBetweenStationsReduced(source, dest);
    if (maxFlow == -1) {
        cout << "INVALID DEPARTURE AND/OR ARRIVAL STATION  " << endl;
        cout << "1) TRY AGAIN                     0) BACK  " << endl;
        cout << "Option: ";
        do {
            cin >> option;
            switch(option) {
                case 1: viewMaxTrainsBetweenStationsReduced(); break;
                case 0: reliAndSensiMenu(); break;
                default: cout << "Invalid option, please try again: ";
            }
        }while(option != 1 && option != 0);
    } else {
        cout << "********************************************************" << endl;
        cout << "   MAXIMUM NUMBER OF TRAINS THAT CAN SIMULTANEOUSLY     " << endl;
        cout << "       TRAVEL BETWEEN TWO SPECIFIC STATIONS IN" << endl;
        cout << "           A NETWORK OF REDUCED CONNECTIVITY" << endl;
        cout << endl;
        cout << "  DEPARTURE STATION: " << source << endl;
        cout << "  ARRIVAL STATION: " << dest << endl;
        cout << "  NUMBER OF TRAINS = " << maxFlow << endl;
        cout << "                                               0) BACK  " << endl;
        cout << "********************************************************" << endl;
        cout << "Option: ";
        do {
            cin >> option;
            if(option == 0)
                reliAndSensiMenu();
            else
                cout << "Invalid option, please try again: ";
        }while(option != 0);
    }
}

/**
 * Prints the top-k stations affected by each segment failure.
 */
void Menu::viewTopkAffectedStations() {
    vector<Station> stats = controller.topkAffectedStations();
}

/**
 * Receives the top-k that the user wants to be showed.
 * @return the top-k chosen by the user;
 */
int Menu::askTopk() {
    cout << "What's the top?: ";
    int k;
    do {
        cin >> k;
        if(k == 0)
            cout << "Invalid number, please insert again: ";
    }while(k == 0);
    return k;
}

/**
 * Receives the user option to return to the main menu.
 */
void Menu::goBackMenu() {
    int option;
    do {
        cin >> option;
        if(option == 0)
            mainMenu();
        else
            cout << "Invalid option, please try again: ";
    }while(option != 0);
}