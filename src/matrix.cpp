/*
 * File: matrix.cpp
 * Description: Implementation file of the module matrix.hpp.
 */
#include <iostream>
#include <cstdlib>
#include "matrix.hpp"
using namespace std;

void createFirstGen(vector<vector<char>> &matrix, char mode) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {

            int r = rand() % 100;

            if (mode == 'C') {
                if (r < 20) {               // 20% chance
                    matrix[i][j] = '*';
                } else {                    // 80% chance
                    matrix[i][j] = ' ';
                } 
            } else {
                if (r < 20) {               // 20% chance
                    matrix[i][j] = 'O';
                } else if (r < 30) {        // 10% chance
                    matrix[i][j] = 'o';
                } else {                    // 70% chance
                    matrix[i][j] = ' ';
                }
            }
        }
    }   
}


void printCell(char cell, char mode) {
    if (mode == 'C') {
        if (cell == '*') {
            cout << "\033[31m*\033[0m";     // Red
        } else {
            cout << ' ';
        }
    } else {
        if (cell == 'O') {
            cout << "\033[32mO\033[0m";     // Green
        } else if (cell == 'o') {
            cout << "\033[33mo\033[0m";     // Yellow
        } else {
            cout << ' ';
        }
    }
    
}


void writeGen(const vector<vector<char>> &matrix, char mode) {
    for (size_t i = 0; i < matrix.size(); i ++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            printCell(matrix[i][j], mode);
        }
        cout << endl;
    }
}


void nextGen(const vector<vector<char>> &originalMatrix, 
        vector<vector<char>> &newMatrix, char mode) {
    for (size_t i = 0; i < originalMatrix.size(); i++) {
        for (size_t j = 0; j < originalMatrix[i].size(); j++) {
            if (mode == 'C') {
                if (thereIsCell(i, j, originalMatrix, '*')) {
                    if (neighborCells(i, j, originalMatrix, mode) == 2 ||
                                neighborCells(i, j, originalMatrix, mode) == 3) {
                        newMatrix[i][j] = '*';
                    } else {
                        newMatrix[i][j] = ' ';
                    }
                } else {
                    if (neighborCells(i, j, originalMatrix, mode) == 3) {
                        newMatrix[i][j] = '*';
                    } else {
                        newMatrix[i][j] = ' ';
                    }
                }
            } else {
                if (thereIsCell(i, j, originalMatrix, 'O')) {
                    if (neighborCells(i, j, originalMatrix, mode) == 2 ||
                                neighborCells(i, j, originalMatrix, mode) == 3) {
                        newMatrix[i][j] = 'O';
                    } else {
                        newMatrix[i][j] = 'o';
                    }
                } else if (thereIsCell(i, j, originalMatrix, 'o')) {
                    if (neighborCells(i, j, originalMatrix, mode) == 8) {
                        newMatrix[i][j] = 'O';
                    } else {
                        newMatrix[i][j] = ' ';
                    }
                } else {
                    if (neighborCells(i, j, originalMatrix, mode) == 3) {
                        newMatrix[i][j] = 'O';
                    } else {
                        newMatrix[i][j] = ' ';
                    }
                }
            }
        }
    }
}



bool equalGenerations(const vector<vector<char>> &genOne, 
        const vector<vector<char>> &genTwo) {
    size_t i = 0;
    bool equal = true;
    while (i < genOne.size() && equal) {
        size_t j = 0;
        while (j < genOne[i].size() && equal) {
            if (genOne[i][j] != genTwo[i][j]) {
                equal = false;
            }
            j++;
        }
        i++;
    }
    return equal; 
}


void copyMatrix(const vector<vector<char>> &originalMatrix, 
        vector<vector<char>> &newMatrix) {
     for (size_t i = 0; i < originalMatrix.size(); i ++) {
        for (size_t j = 0; j < originalMatrix[i].size(); j++) {
            newMatrix[i][j] = originalMatrix[i][j];
        }
    }
}