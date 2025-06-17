#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Bubble sort on a vector passed by reference
void bubble(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream numfile(argv[1]); // Open input file

    vector<int> numbers;
    int number;

    // Read numbers from file into vector
    while (numfile >> number) {
        numbers.push_back(number);
    }
    numfile.close(); // Close input file

    cout << "Starting bubble sort with " << numbers.size() << " numbers" << endl;

    bubble(numbers); // Sort the numbers using bubble sort

    cout << "Finished bubble sort" << endl;

    ofstream outfile(argv[2]); // Open output file
    
    // Write sorted numbers to output file
    for (int i = 0; i < (int)numbers.size(); i++) {
        outfile << numbers[i] << endl;
    }

    outfile.close(); // Close output file
    return 0;
}
