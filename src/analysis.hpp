/*
 * File: analysis.hpp
 * Description: Header file containing the declarations for calculating system 
 * statistics.
 */
#pragma once

#include "data.hpp"
#include "rules.hpp"
#include <vector>

/*
 * Struct: Stats
 * Description: Holds the numerical and percentage data of the population 
 * for a specific generation.
 */
struct Stats {
    int aliveCells;
    int refractoryCells;
    int activeCells;
    double alivePercentage;
    double refractoryPercentage;
    double activePercentage;
    int totalCells;
};

/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A".
 * Post: Returns "true" if there are not more alive cells.
 */ 
bool isExtinct(const std::vector<std::vector<char>> &matrix, char mode);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A".
 * Post: Calculates the statistics of the matrix based on its number of cells 
 *       and stores the results in "s".
 */ 
void calculateStatistics(const std::vector<std::vector<char>> &matrix, 
        Stats &s, char mode);


/*
 * Pre:  "matrix" must be initialized and its dimensions strictly greater than 0.
 *       "mode" is "C" or "A", "s" contains the statistics of "matrix" and 
 *       "maxAliveCells" contains the highest historic value of alive cells.
 * Post: Shows on screen the main statistics of the current matrix with a
 *       special format.
 */ 
void showStatistics(const std::vector<std::vector<char>> &matrix, Stats s, 
        const int maxAliveCells, char mode);

