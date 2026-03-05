/*
 * File: data.hpp
 * Description: Header file containing the declarations for data solicitation.
 */
#pragma once

#include "rules.hpp"

/*
 * Struct: GameSettings
 * Description: Holds the parameters that govern the simulation.
 */
struct GameSettings {
    int rows;
    int cols;
    int nGenerations;
    char gameMode;           // 'C' = Classic mode, 'A' = Alternative mode
    char displayMode;        // 'F' = Fast mode, 'N' = Normal mode
};

/*
 * Pre:  true
 * Post: Prompts the user for the necessary data to launch the simulation and
 *       stores the input in "gS".
 */ 
void dataSolicitation(GameSettings &gS);
