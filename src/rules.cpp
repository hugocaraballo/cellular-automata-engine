/*
 * File: rules.cpp
 * Description: Implementation file of the module rules.hpp.
 */
#include "rules.hpp"

#include <iostream>
using namespace std;

int countCells(const vector<vector<char>> &matrix, const char state) {
    int counter = 0;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == state) {
                counter++;
            }
        }
    }
    return counter;
}


int totalActiveCells(const vector<vector<char>> &matrix, int &alive, 
        int &refractory, char mode) {
    if (mode == 'C') {
        alive = countCells(matrix, '*');
        refractory  = 0;
        return alive;
    } else {
        alive = countCells(matrix, 'O');
        refractory = countCells(matrix, 'o');
        return alive + refractory;
    }
            
}


bool thereIsCell(const int i, const int j,  const vector<vector<char>> &matrix,
        const char state) {
    if (i < 0 || i >= static_cast<int>(matrix.size()) || j < 0 
              || j >= static_cast<int>(matrix[i].size())) {
        return false;
    } else {
        return (matrix[i][j] == state);
    }
}


int neighborCells(int i, int j, const vector<vector<char>> &matrix, char mode) {
    int counter = 0;
    for (int row = i - 1; row < i + 2; row++) {
        for (int col = j - 1; col < j + 2; col++) {
            if (row == i && col == j) {
                ;                                               // It is the cell
            } else if (mode == 'C' && thereIsCell(row, col, matrix, '*')) {
                counter++;
            } else if (thereIsCell(row, col, matrix, 'O')) {
                counter++;
            }
        }
    }
    return counter;
}