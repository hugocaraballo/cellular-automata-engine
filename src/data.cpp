/*
 * File: data.cpp
 * Description: Implementation file of the module data.hpp.
 */
#include "data.hpp"

#include <iostream>
using namespace std;

void dataSolicitation(GameSettings &gS) {
    cout << "Write down the number of rows: ";
    cin >> gS.rows;

    cout << "Write down the number of columns: ";
    cin >> gS.cols;

    cout << "Write down the number of generations: ";
    cin >> gS.nGenerations;

    cout << "Write 'C' if you want Classic mode or 'A' if"
         << "you want Alternative Mode: ";
    cin >> gS.gameMode;

    cout << "Write 'F if you want Fast mode or 'N' if"
         << "you want Normal mode: ";
    cin >> gS.displayMode;


    cout << endl << endl;

    if (gS.cols > 225) {
        cout << "\033[31mWarning\033[0m";
        cout << ": The simulation may not be displayed correctly" << endl 
             << endl;
       
    }
}
