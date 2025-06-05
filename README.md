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
