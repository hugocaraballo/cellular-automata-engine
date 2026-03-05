/*
 * File: analysis.cpp
 * Description: Implementation file of the module analysis.hpp.
 */
#include "analysis.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

bool isExtinct(const vector<vector<char>> &matrix, char mode) {
    size_t i = 0;
    bool extinction = true;
    while (i < matrix.size() && extinction) {
        size_t j = 0;
        while (j < matrix[i].size() && extinction) {
            if (mode == 'C') {
                if (matrix[i][j] == '*') {
                    extinction = false;
                }
            } else {
                if (matrix[i][j] == 'o' || matrix[i][j] == 'O') {
                    extinction = false;
                }
            }
            j++;
        }
        i++;
    }
    return extinction;
}


void calculateStatistics(const vector<vector<char>> &matrix, Stats &s, char mode) {
    s.totalCells = matrix.size() * matrix[0].size();
    s.activeCells = totalActiveCells(matrix, s.aliveCells, s.refractoryCells, mode);
    s.alivePercentage = (double)s.aliveCells / (double)s.totalCells * 100; 
    s.refractoryPercentage = (double)s.refractoryCells / (double)s.totalCells * 100;
    s.activePercentage = (double)s.activeCells / (double)s.totalCells * 100;
}



void showStatistics(const vector<vector<char>> &matrix, const Stats s, 
            const int maxAliveCells, char mode) {
    cout << setfill('-') << setw(matrix[0].size()) << "-" << endl;
    cout << "   Statistics:" << endl;
    cout << setfill('-') << setw(matrix[0].size()) << "-" << endl;

    cout << "Alive cells: " << s.aliveCells << " (" << fixed << setprecision(2) 
         << s.alivePercentage << ")%" << endl;
    if (mode == 'A') {
        cout << "Refractory cells: " << s.refractoryCells << " (" << fixed 
             << setprecision(2) << s.refractoryPercentage << ")%" << endl;
        cout << "Active cells: " << s.activeCells << " (" << fixed << setprecision(2) 
             << s.activePercentage << ")%" << endl;
    }
    cout << "Maximum alive cells: " << maxAliveCells << endl << endl;
}