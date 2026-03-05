/*
 * File: simulation.cpp
 * Description: Implementation file of the module simulation.hpp.
 */
#include "simulation.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

void simulation(const GameSettings &gS) {
    vector<vector<char>> originalMatrix(gS.rows, vector<char>(gS.cols));
    vector<vector<char>> newMatrix(gS.rows, vector<char>(gS.cols));

    bool extinction = false;
    bool equalGens = false;
    int maxCellsOne = 0;
    char version = gS.gameMode;
    char display = gS.displayMode;
    bool isFastMode = (display == 'F');
    Stats s;

    int dimension = gS.rows * gS.cols;
    cout << "System generated with " << dimension << " cells."<< endl << endl;

    createFirstGen(originalMatrix, version);
    if (!isFastMode) {
        writeGen(originalMatrix, version);
    }
    calculateStatistics(originalMatrix, s, version);

    if (version == 'C') {
        maxCellsOne = countCells(originalMatrix, '*');
    } else {
        maxCellsOne = countCells(originalMatrix, 'O');
    }

    if (!isFastMode) {
        showStatistics(originalMatrix, s, maxCellsOne, version);
    }

    int i = 1;
    while (i <= gS.nGenerations && !extinction && !equalGens) {
        nextGen(originalMatrix, newMatrix, version);
        
        int maxCellsTwo;
        if (version == 'C') {
            maxCellsTwo = countCells(newMatrix, '*');
        } else {
            maxCellsTwo = countCells(newMatrix, 'O');
        }
        if (maxCellsTwo > maxCellsOne) {
            maxCellsOne = maxCellsTwo;
        }
        calculateStatistics(newMatrix, s, version);

        extinction = isExtinct(newMatrix, version);
        equalGens = equalGenerations(originalMatrix, newMatrix);

        copyMatrix(newMatrix, originalMatrix);

        if (!isFastMode) {       
            cout << setfill('-') << setw(newMatrix[0].size()) << "-" << endl;
            cout << "   Generation " << i << ":" << endl;
            cout << setfill('-') << setw(newMatrix[0].size()) << "-" << endl;
            writeGen(newMatrix, version);
            showStatistics(newMatrix, s, maxCellsOne, version);

            if (extinction) {
                cout << "There are no longer living cells" << endl;
            } else if (equalGens) {
                cout << "The system has become stabilized in generation: " 
                     << i << endl;
            }
        }        
        i++;
    }
    if (isFastMode) {
        cout << setfill('-') << setw(newMatrix[0].size()) << "-" << endl;
            cout << "   Final generation (" << i - 1 << "):" << endl;
            cout << setfill('-') << setw(newMatrix[0].size()) << "-" << endl;
            writeGen(originalMatrix, version);
            showStatistics(originalMatrix, s, maxCellsOne, version);

        if (extinction) {
            cout << "There are no longer living cells" << endl << endl;
        } else if (equalGens) {
            cout << "The system has become stabilized in generation: " 
                 << i - 1 << endl << endl;
        }
    }
}