/*
 * File: main.cpp
 * Description: Entry point of the Game of Life application. It handles 
 * user input for simulation settings, seeds the random number generator, 
 * orchestrates the main simulation, and performs high-precision CPU benchmarking.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "simulation.hpp"
#include "rules.hpp"
#include "data.hpp"
#include "matrix.hpp"
#include "analysis.hpp"
using namespace std;

/*
 * Pre:  The underlying system supports POSIX clock_gettime for benchmarking.
 * Post: Executes the full simulation lifecycle based on user input and outputs 
 *       the exact CPU execution time if Fast Mode is selected. Returns 0 upon 
 *       successful completion.
 */
int main() {
    GameSettings settings;
    dataSolicitation(settings);
    srand(time(nullptr));

    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    simulation(settings);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    if (settings.displayMode == 'F') {
        long secs = end.tv_sec - start.tv_sec;
        long nanosecs = end.tv_nsec - start.tv_nsec;
        double totalSecs = secs + nanosecs * 1e-9;

        cout << "Total CPU time (Fast Mode): " << fixed << setprecision(6) 
             << totalSecs << " seconds" << endl << endl;
    }
    return 0;
}