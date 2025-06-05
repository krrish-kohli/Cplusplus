#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

int main() {
    int p1win = 0;
    int p2win = 0;
    int p1loss = 0;
    int p2loss = 0;
    int p1tie = 0;
    int p2tie = 0;

    Deck myDeck; // Step 1: Create a deck of cards

    cout << "Enter the name of the first player: " << endl; // Step 2: Get player names
    string p1, p2;
    cin >> p1;
    cout << "Enter the name of the second player: " << endl;
    cin >> p2;

    cout << "\n Original Deck" << endl;
    myDeck.display(); // Step 3: Display the deck

    myDeck.shuffle(); // Step 4: Shuffle the deck

    cout << "Shuffled Deck" << endl;
    myDeck.display(); // Step 5: Display the shuffled deck

    // Play 26 rounds
    for (int round=0; round < 26; round++){
        Card p1card = myDeck.deal(); // Step 6: Draw a card from the deck
        Card p2card = myDeck.deal(); // Step 7: Draw a card from the deck

        int result = p1card.compare(p2card); // Step 8: Compare the cards

        cout << "Game " << (round+1) << endl;
        cout << "--------" << endl;

        cout << "\t" << p1 << " => ";
        p1card.display();
        cout << endl;

        cout << "\t" << p2 << " => ";
        p2card.display();
        cout << endl;

        if (result > 0) { // Step 9: Determine the winner
            cout << "\t" << p1 << " => Winner" << endl; // Step 10: Display the winner
            p1win++;
            p2loss++;
        } else if (result < 0) {
            cout << "\t" << p2 << " => Winner" << endl; // Step 10: Display the winner
            p2win++;
            p1loss++;
        } else {
            cout << "\t Tie game" << endl; // Step 10: Display the tie
            p1tie++;
            p2tie++;
        }
    }

    cout << "------ Final Stats -------" << endl;
    cout << "\t" << p1 << " vs. " << p2 << endl;
    cout << "Wins    " << p1win << "\t\t" << p2win << endl;
    cout << "Losses  " << p1loss << "\t\t" << p2loss << endl;
    cout << "Ties    " << p1tie << "\t\t" << p2tie << endl;

    return 0;
}
