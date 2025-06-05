# ifndef Card_h
# define Card_h

# include <string>

class Card{
    private:
        char rank;
        char suit;
    public:
        Card();
        Card(char r, char s);
        int compare(Card);
        void display();
};

# endif
