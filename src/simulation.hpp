/*
 * File: simulation.hpp
 * Description: Header file containing the declarations for maanging the main
 * simulation loop and the game's lifecycle.
 */
#pragma once

#include "matrix.hpp"
#include "rules.hpp"
#include "analysis.hpp"
#include "data.hpp"

/*
 * Pre:  "gS" contains valid settings (rows and columns strictly greater than 0, 
 *       valid generation limit, and valid game/display modes).
 * Post: Executes the Game of Life simulation according to the parameters in "gS". 
 *       The loop halts when the generation limit is reached, the population 
 *       goes extinct, or the grid reaches a stable state.
 */
void simulation(const GameSettings &gS);