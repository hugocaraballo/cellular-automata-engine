#  Cellular Automata Engine

A highly optimized, modular implementation of Conway's Game of Life written in modern C++ (C++17). This project is designed with a strong focus on algorithmic efficiency, strict structured programming principles, memory safety, and accurate CPU benchmarking.

##  Key Features

* **High-Performance Benchmarking:** Bypasses standard terminal I/O in 'Fast Mode' to compute generations at maximum speed. It measures raw CPU execution time using POSIX `CLOCK_PROCESS_CPUTIME_ID` with microsecond precision, effectively isolating the simulation from OS wall-clock interruptions.
* **Streamlined Terminal Rendering:** Features clean terminal output using native ANSI escape codes for color formatting. It avoids heavy, OS-dependent console clearing commands (`system("clear")`), ensuring cross-platform safety and performance.
* **Implicit Dead Borders:** The simulation engine safely handles out-of-bounds coordinate requests without crashing, treating them as dead cells to optimize edge-case checking loops.
* **Modular Architecture:** Strict Separation of Concerns (SoC). The engine is divided into independent, highly cohesive modules (`simulation`, `analysis`, `data`, `matrix`, `rules`) decoupled from the main execution loop.

##  Architecture overview

* `data.hpp`: Single source of truth for the engine's state and simulation settings.
* `simulation`: Manages the main engine loop and lifecycle (halting on extinction, stagnation, or generation limits).
* `rules`: Governs cell neighborhood inspection, boundary validation (Implicit Dead Borders), and active cell counting.
* `analysis`: Calculates population statistics and evaluates the grid's state.
* `matrix`: Handles all 2D vector memory operations, state rendering, and executes the core generation transitions (`nextGen`).

##  Build & Run

This project includes a `Makefile` for automated, optimized compilation across Unix-like systems (macOS/Linux).

1. Clone the repository and navigate to the project directory.
2. Build the engine using `make` (this will automatically apply the `-O3` optimization flag):
```
make
```
3. Run the compiled executable:

```
./simulator
```
(Note: To clean the compiled objects and executable, run `make clean`)

## Results
| Classic Mode | Alternative Mode |
| :---: | :---: |
| <img width="728" height="469" alt="Captura de pantalla 2026-03-27 a las 9 33 19" src="https://github.com/user-attachments/assets/68990188-4fb8-4f3f-9ba5-48791eacc868" /> | <img width="722" height="483" alt="Captura de pantalla 2026-03-27 a las 9 34 04" src="https://github.com/user-attachments/assets/1c76265e-54d0-4d95-b6f4-1b0fc2ff3f84" /> |



##  Engine Modes
Upon launching, the engine prompts for grid dimensions, maximum generations, and rendering mode:

1. Normal Mode ('N'): Renders the cellular automata evolution to the standard output step-by-step. Ideal for observing gliders, oscillators, and stable structures.

2. Fast Mode ('F'): Disables all visual output. Computes all generations purely in memory until a halt condition is met, finally outputting the end state and the exact CPU execution time.
