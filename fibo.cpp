// Author: Krrish Kohli
// CECS 325-01 Prog 0
// Due 05/30/2025

#include <iostream> // library for cin, cout
# include <string>

using namespace std; // allows shortcuts

// Fibo function
int fibo(int n) // functions must be declared before use
{
    if (n == 1 || n == 0)
        return 1;
    else
        return fibo(n-1) + fibo(n-2); // recursion
}

int main()
{
    string name;
    int number;
    cout << "What is your name? ";
    cin >> name;
    cout << "What is your favorite number? ";
    cin >> number;
    if (number % 2 == 0)
        cout << "Your number is even" <<endl;
    else
        cout << "Your number is odd" << endl;
        
    cout << "Welcome to class " <<name<<endl;
    
    for (int i = 0; i <= 20; i++)
        cout << i << ":" << fibo(i)<<endl;
    return 0;
}
