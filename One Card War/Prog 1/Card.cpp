# include <iostream>

# include "Card.h"

using namespace std;

Card::Card(){
    rank = 'X';
    suit = 'X';
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
}

void Card::display(){
    if (rank == 'T') {
        cout << "10" << suit;
    } else {
        cout << rank << suit;
    }
}

int Card::compare(Card other){
    int thisValue;
    int otherValue;

    if (rank == 'A') {
        thisValue = 1;
    } else if (rank == '2') {
        thisValue = 2;
    } else if (rank == '3') {
        thisValue = 3;
    } else if (rank == '4') {
        thisValue = 4;
    } else if (rank == '5') {
        thisValue = 5;
    } else if (rank == '6') {
        thisValue = 6;
    } else if (rank == '7') {
        thisValue = 7;
    } else if (rank == '8') {
        thisValue = 8;
    } else if (rank == '9') {
        thisValue = 9;
    } else if (rank == 'T') {
        thisValue = 10;
    } else if (rank == 'J') {
        thisValue = 11;
    } else if (rank == 'Q') {
        thisValue = 12;
    } else if (rank == 'K') {
        thisValue = 13;
    } else {
        thisValue = 0;
    }

    if (other.rank == 'A') {
        otherValue = 1;
    } else if (other.rank == '2') {
        otherValue = 2;
    } else if (other.rank == '3') {
        otherValue = 3;
    } else if (other.rank == '4') {
        otherValue = 4;
    } else if (other.rank == '5') {
        otherValue = 5;
    } else if (other.rank == '6') {
        otherValue = 6;
    } else if (other.rank == '7') {
        otherValue = 7;
    } else if (other.rank == '8') {
        otherValue = 8;
    } else if (other.rank == '9') {
        otherValue = 9;
    } else if (other.rank == 'T') {
        otherValue = 10;
    } else if (other.rank == 'J') {
        otherValue = 11;
    } else if (other.rank == 'Q') {
        otherValue = 12;
    } else if (other.rank == 'K') {
        otherValue = 13;
    } else {
        otherValue = 0;
    }

    if (thisValue > otherValue) {
        return 1;
    } else if (thisValue < otherValue) {
        return -1;
    } else {
        return 0;
    }
}
