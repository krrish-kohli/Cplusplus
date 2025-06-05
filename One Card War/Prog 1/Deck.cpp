#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

using namespace std;

Deck::Deck() {
    char suits[4] = {'S', 'C', 'D', 'H'};
    char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[index] = Card(ranks[j], suits[i]);
            index++;
        }
    }
    top = 0;
}

Card Deck::deal() {
    if (top >= 52) {
        return Card();
    }
    return cards[top++];
}

void Deck::display() {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 13; col++) {
            int idx = row * 13 + col;
            cards[idx].display();
            if (col < 12) {
                cout << ",";
            }
        }
        cout << endl << endl;
    }
}

void Deck::shuffle() {
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    top = 0;
}