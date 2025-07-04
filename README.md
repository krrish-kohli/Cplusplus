# C++

Welcome to the **C++** repository! This is a collection of C++ programs created as part of coursework, practice, and personal projects. Each folder contains a self-contained program with its own source code and build instructions.

---

## 📁 Projects

### 🔹 `fibo`
A basic C++ program that:
- Prompts the user for their name and favorite number
- Identifies whether the number is odd or even
- Displays a personalized greeting
- Recursively calculates and prints the first 21 Fibonacci numbers

**Files:**
- `fibo.cpp` — Source code
- `a.out` — Compiled binary

**Run it:**
```bash
cd fibo/'Prog 0' 
c++ fibo.cpp
./a.out
```


### 🔹 `One Card War`  
A C++ program that simulates a simple card game where two players compete over 26 rounds. The program:

- Initializes and displays a standard deck of cards  
- Shuffles the deck before gameplay  
- Prompts for two player names  
- Deals one card to each player per round and compares their values  
- Tracks wins, losses, and ties for each player  
- Displays the final results after all rounds  

**Files:**  
- `Deck.h` — Declaration of the `Deck` class managing a collection of cards
- `Deck.cpp` — Implementation of the `Deck` class functions including shuffle and deal
- `Card.h` — Declaration of the `Card` class representing individual playing cards
- `Card.cpp` — Implementation of the `Card` class functions including comparison and display
- `main.cpp` — Contains the game logic and user interaction for the One Card War game
- `war` - Compiled binary

**Run it:**  
```bash
cd 'One Card War'/'Prog 1'
c++ Deck.cpp Card.cpp main.cpp -o war
./war
```


### 🔹 `Solitaire`  
A C++ program that simulates **Fibonacci Solitaire**, a card game where cards are dealt into piles, and each pile must sum to a Fibonacci number to continue the game. The program:

- Includes a menu with multiple gameplay options
- Generates a new standard 52-card deck
- Shuffles and displays the deck
- Plays a game of Fibonacci Solitaire by dealing cards into Fibonacci-sum piles
- Simulates automatic games until a win is found
- Determines if a number is Fibonacci using a recursive check

**Files:**
- `Solitaire.cpp` — Contains full implementation of the `Card` and `Deck` classes, Fibonacci checking logic, and game loop

**Run it:**
```bash
cd Solitaire/'Prog 2'
c++ Solitaire.cpp -o solitaire
./solitaire
```


### 🔹 `Sort Contest`  
A C++ project that benchmarks a custom bubble sort implementation against the system's built-in sort using 1,000,000 randomly generated integers. The program:

- Generates a large set of random numbers using command-line arguments
- Sorts the data using both system sort and a custom bubble sort
- Logs execution time, verifies sort correctness, and stores results

**Files:**  
- `generate.cpp` — Generates random numbers between a given min and max and writes them to `numbers.dat`  
- `generate` — Executable for generating the data  
- `mysort.cpp` — Reads numbers from `numbers.dat`, sorts them using bubble sort, and writes to `mysort.out`  
- `mysort` — Executable for running the bubble sort  
- `sortrace.sh` — Shell script to automate the full benchmark process  
- `sortrace.log` — Log file recording the runtime and performance output  
- `numbers.dat` — Input file containing the generated random numbers  
- `mysort.out` — Output file containing numbers sorted by your bubble sort  
- `systemsort.out` — Output file from the system's built-in `sort` command  

**Run it:**
```bash
# Step 1: Compile the C++ programs
cd 'Sort Contest'/'Prog 3'
c++ generate.cpp -o generate
c++ mysort.cpp -o mysort

# Step 2: Give execute permission to the script
chmod +x sortrace.sh

# Step 3: Remove old log file (optional but recommended)
rm sortrace.log

# Step 4: Run the sort contest (as a background task)
./sortrace.sh >> sortrace.log &
```


### 🔹 `Sort Contest (With Threads)`  
A C++ program that benchmarks a **multithreaded bubble sort** against the system's built-in sort using 1,000,000 randomly generated integers. The program:

- Generates a large set of random numbers using command-line arguments  
- Uses 16 threads to sort the data in parallel using bubble sort  
- Merges sorted chunks into a final, completely sorted array  
- Logs the number of swaps performed by each thread  
- Compares output against system sort for correctness  
- Logs all execution details to a file for analysis

**Files:**  
- `generate.cpp` — Generates `numbers.dat` with random numbers between a given min and max
- `generate` — Executable for generating the data
- `mysort.cpp` — Reads numbers from `numbers.dat`, sorts them using multithreaded bubble sort, and writes to `mysort.out`
- `mysort` — Executable for running the threaded bubble sort
- `numbers.dat` — Input file containing the generated random numbers
- `mysort.out` — Output file containing numbers sorted by your threaded sort
- `systemsort.out` — Output file from the system’s built-in `sort` command
- `sortrace.sh` — Shell script to automate compilation, sorting, timing, and verification
- `sortrace.log` — Log file recording the runtime, swap counts, and comparison results

**Run it:**  
```bash
# Step 1: Compile the C++ programs
cd 'Sort Contest (With Threads)'/'Prog 4'
c++ generate.cpp -o generate
c++ mysort.cpp -pthread -o mysort

# Step 2: Give execute permission to the script
chmod +x sortrace.sh

# Step 3: Start with a clean log file (optional)
rm sortrace.log

# Step 4: Run the sort contest
./sortrace.sh >> sortrace.log &
```


### 🔹 `GoldRabbits`  
A C++ program that computes Fibonacci numbers using recursion with memoization. It accepts one or more command-line arguments and calculates each corresponding Fibonacci number. The program:

- Uses a `map` to memoize previously computed values  
- Accepts multiple inputs from the command line  
- Detects and reports overflow conditions (based on signed integer behavior)  
- Prints the full contents of the Fibonacci map when `-1` is passed  
- Handles non-integer inputs with error messages  

**Files:**  
- `goldrabbits.cpp` — Source code with Fibonacci calculation, overflow handling, and map printing
- `goldrabbits` — Compiled executable
- `goldrabbits.log` — Sample log showing results for valid inputs, overflow errors, map output, and invalid input handling

**Run it:**  
```bash
cd GoldRabbits/'Prog 5'
c++ goldrabbits.cpp -o goldrabbits
./goldrabbits 4 6 3 monkey 9000 horse 45 47 -1
```
