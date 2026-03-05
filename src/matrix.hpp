/*
 * File: matrix.hpp
 * Description: Header file containing the declarations for working with matrices.
 */
#pragma once

#include <iostream>
#include <vector>
#include "rules.hpp"

/*
 * Pre:  "matrix" dimensions are strictly greater than 0, "mode" is "C" or "A".
 * Post: Creates the first generation of the game with different probabilities
 *       for each kind of cell.
 */ 
void createFirstGen(std::vector<std::vector<char>> &matrix, char mode);


/*
 * Pre:  "cell" is 'O' , 'o' , '*' or ' ' and "mode" is "C" or "A".
 * Post: Prints the cell to the standard output with its respective color.
 */ 
void printCell(char cell, char mode);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A".
 * Post: Prints the entire matrix to the standard output.
 */ 
void writeGen(const std::vector<std::vector<char>> &matrix, char mode);


/*
 * Pre:  "originalMatrix" must be initialized and its dimensions strictly 
 *       greater than 0, "mode" is "C" or "A".
 * Post: Creates the next generation based on "originalMatrix" and "mode", 
 *       and stores the result in "newMatrix".
 */ 
void nextGen(const std::vector<std::vector<char>> &originalMatrix, 
        std::vector<std::vector<char>> &newMatrix, char mode);


/*
 * Pre:  "genOne" and "genTwo" must be initialized and its dimensions strictly 
 *       greater than 0 and equal.
 * Post: Returns true if all the elements of both matrixcs are exactly equal.
 */ 
bool equalGenerations(const std::vector<std::vector<char>> &genOne, 
        const std::vector<std::vector<char>> &genTwo);


/*
 * Pre:  "originalMatrix" and "newMatrix" must be initialized and their 
 *       dimensions strictly greater than 0 and equal to each other.
 * Post: Copies all the contents from "originalMatrix" into "newMatrix".
 */
void copyMatrix(const std::vector<std::vector<char>> &originalMatrix, 
        std::vector<std::vector<char>> &newMatrix);