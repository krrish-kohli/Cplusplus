#include <fstream> //For the file
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 4){
        cout << "Enter 3 parameters" << endl;
        cout << "1 - Amount of numbers to be generated" << endl;
        cout << "2 - Minimum value" << endl;
        cout << "3 - Maximum value" << endl;
        return 1;
    }
    
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    }
    
    int amount = stoi(argv[1]);
    int minimum = stoi(argv[2]);
    int maximum = stoi(argv[3]);
    cout << amount << " numbers being generated between " << minimum << " and " << maximum << endl;

    ofstream numfile; //Creates a file to store the numbers
    numfile.open("numbers.dat", ios::out); //Creates numbers.dat

    srand(time(0));
    for (int i = 0; i < amount; i++) {
        numfile << (rand() % (maximum - minimum + 1)) + minimum << endl; //Adds a random number to numbers.dat
    }
    
    numfile.close(); //Closes the file
    return 0;
    }