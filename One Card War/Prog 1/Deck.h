# ifndef Deck_h
# define Deck_h

# include "Card.h"

class Deck{
    private:
        Card cards[52];
        int top;
    public:
        Deck();
        Card deal();
        void display();
        void shuffle();
};

# endif
