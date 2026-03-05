/*
 * File: rules.hpp
 * Description: Header file containing the declarations for tracking cells.
 */
#pragma once

#include <vector>


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "state" is 'O', 'o', or '*'.
 * Post: Counts and returns the number of times that "state" appears in "matrix".
 */ 
int countCells(const std::vector<std::vector<char>> &matrix, const char state);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A".
 * Post: Calculates the number of alive and refractory cells, storing the results 
 *       in "alive" and "refractory". Returns the total number of active cells.
 */ 
int totalActiveCells(const std::vector<std::vector<char>> &matrix, int &alive, 
        int &refractory, const char mode);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "state" is 'O', 'o', or '*'.
 * Post: Returns true if the cell at position (i, j) matches "state". Returns 
 *       false if the state does not match or if the coordinates are out of bounds.
 */ 
bool thereIsCell(const int i, const int j, 
        const std::vector<std::vector<char>> &matrix, const char state);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A".
 * Post: Returns the number of neighbor cells around the position (i, j). 
 *       Out-of-bounds coordinates are safely treated as dead cells.
 */ 
int neighborCells(int i, int j, const std::vector<std::vector<char>> &matrix, 
        const char mode);
