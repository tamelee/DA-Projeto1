#include "Menu.h"

void Menu::appMenu() {
    cout << "********************************" << endl;
    cout << "*                              *" << endl;
    cout << "*    Railway                   *" << endl;
    cout << "*      Network                 *" << endl;
    cout << "*                              *" << endl;
    cout << "*     1) DATA SET FILES        *" << endl;
    cout << "*     2) OPERATIONS            *" << endl;
    cout << "*     0) SAIR                  *" << endl;
    cout << "*                              *" << endl;
    cout << "*                              *" << endl;
    cout << "********************************" << endl;
    int option;
    do{
        cin >> option;
        switch(option) {
            case 1: break;
            case 2: break;
            case 0: exit(0);
            default: cout << "Opcao invalida, por favor tente novamente: ";
        }
    } while(option != 0 && option != 1 && option != 2);
}