// Name: Krrish Kohli
// Class (CECS 325-01)
// Project Name (Prog 5 – goldRabbits)
// Due Date (06/28/2025)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <map>
#include <string>

using namespace std;

#define INTEGER int        // use int for Fibonacci numbers
// #define INTEGER short    // use short if you want smaller numbers
// #define INTEGER long long // use long long for very big numbers

INTEGER goldRabbits(INTEGER n) {
    static map<INTEGER, INTEGER> rabbitMap = { {0, 1}, {1, 1} };

    if (n == -1) {
        cout << "Fibo Map contents:" << endl;
        for (auto const& entry : rabbitMap) {
            cout << entry.first << ":" << entry.second << endl;
        }
        cout << "end of Fibo map" << endl;
        return 0;
    }

    if (rabbitMap.count(n)) {
        return rabbitMap[n];
    }

    INTEGER value1 = goldRabbits(n - 1);
    INTEGER value2 = goldRabbits(n - 2);

    // if either is already negative, overflow happened earlier
    if (value1 < 0) throw to_string(n - 1);
    if (value2 < 0) throw to_string(n - 2);

    INTEGER sum = value1 + value2;
    if (value1 > 0 && value2 > 0 && sum < value1) {
        rabbitMap[n] = sum;
        throw to_string(n);
    }


    rabbitMap[n] = sum;
    return sum;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        long long temp;

        try {
            temp = stoll(arg);
        } catch (...) {
            cout << arg << " is not an integer" << endl;
            continue;
        }

        INTEGER n = static_cast<INTEGER>(temp);

        if (n == -1) {
            cout << "fibo(-1):" << endl;
            goldRabbits(-1);
            cout << endl;

        } else if (n >= 0) {
            try {
                INTEGER result = goldRabbits(n);
                cout << "fibo(" << n << "): " << result << endl;
            } catch (string const& overflowIndex) {
                INTEGER idx = static_cast<INTEGER>(stoi(overflowIndex));
                INTEGER value = goldRabbits(idx);
                cout << "fibo(" << n << "): overflow error at fib(" 
                    << overflowIndex << "):" << value << endl;
            }
        } else {
            cout << arg << " is not an integer" << endl;
        }
    }
    return 0;
}