#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Card class
class Card {
private:
    char rank; // 'A', '2'...'9', 'T', 'J', 'Q', 'K'
    char suit; // 'S', 'H', 'D', 'C'
public:
    Card(char r, char s){
        rank = r;
        suit = s;
    }

    void display() const {
        if (rank == 'T') cout << 10 << suit;
        else cout << rank << suit;
    }

    int getValue() const {
        if (rank == 'A') return 1;
        if (rank >= '2' && rank <= '9') return rank - '0';
        return 10;
    }

    int compare(Card other) const {
        int v1 = getValue();
        int v2 = other.getValue();
        if (v1 > v2) return 1;
        if (v1 < v2) return -1;
        return 0;
    }
};

// Deck class
class Deck {
    private:
        vector<Card> cards;
    public:
        Deck() {
            char suits[4] = {'S', 'H', 'D', 'C'};
            char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
            int index = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 13; j++) {
                    cards.push_back(Card(ranks[j], suits[i]));
                    index++;
                }
            }
        }

        Card deal() {
            if (cards.empty())
                throw runtime_error("Deck is empty!!");
            Card c = cards.front();
            cards.erase(cards.begin());
            return c;
        }
        
        void display() {
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

        void shuffle() {
            static bool seeded = false;
            if (!seeded) {
                srand(time(0));
                seeded = true;
            }

            for (int i = cards.size() - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
};

// Check Fibonacci numbers
bool isFibo(int n) {
    if (n < 1) {
        return false;
    }

    int a = 1, b = 1;
    if (n == 1) {
        return true;
    }

    while (b < n) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b == n;
}

int main() {
    Deck deck;
    int choice;
    cout << "Welcome to Fibonacci Solitaire!" << endl;
    while (true) {
        cout << "1) Create New Deck" << endl;
        cout << "2) Display Deck" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Fibo Solitaire" << endl;
        cout << "5) Win Fibo Solitaire" << endl;
        cout << "6) Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        if (choice == 1) {
            deck = Deck();
            cout << "New deck created." << endl;
        } else if (choice == 2) {
            deck.display();
        } else if (choice == 3) {
            deck.shuffle();
            cout << "Deck shuffled." << endl;
            deck.display();
        } else if (choice == 4) {
            int sum = 0;
            int piles = 0;
            cout << "Playing Fibonacci Solitaire!!!" << endl;
            try {
                while (true) {
                    sum = 0;
                    piles++;

                    while (true) {
                        Card c = deck.deal();
                        sum += c.getValue();
                        c.display();
                        if (isFibo(sum)) {
                            cout << ", Fibo:" << sum << endl;
                            break;
                        } else {
                            cout << ", ";
                        }
                    }
                }
            } catch (...) {
                if (sum == 0) {
                    cout << "Winner in " << piles << " piles!" << endl;
                } else {
                    cout << "Last pile not Fibo: " << sum << endl;
                    cout << "Loser in " << piles << " piles!" << endl;
                }
            }
        } else if (choice == 5) {
            int games = 0;
            bool won = false;
            while (!won) {
                games++;
                Deck tempDeck;
                tempDeck.shuffle();
                int piles = 0;
                int sum = 0;
                
                try {
                    while (true) {
                        if (sum == 0) {
                            piles++;
                        }
                        Card c = tempDeck.deal();
                        sum += c.getValue();
                        c.display();
                        
                        if (isFibo(sum)) {
                            cout << " Fibo: " << sum << endl;
                            sum = 0;
                        } else {
                            cout << ", ";
                        }
                    }
                } catch (runtime_error& e) {
                    if (sum == 0) {
                        cout << "Winner in " << piles << " piles!" << endl;
                        won = true;
                    }
                }
        }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid option. Try again." << endl;
        }
    }
    return 0;
}