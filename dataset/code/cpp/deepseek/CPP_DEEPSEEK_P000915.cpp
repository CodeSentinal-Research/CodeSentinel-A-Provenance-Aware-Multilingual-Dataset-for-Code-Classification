Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

long long handshakes(int n) {
    if (n == 1)
        return 0;
    else
        return n * (n - 1) / 2;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    if (n < 1 || n > 500) {
        cout << "Invalid input. Please enter a number between 1 and 500.";
        return 1;
    }

    cout << "Number of handshakes: " << handshakes(n);

    return 0;
}

This program calculates the number of handshakes by using the formula for the number of handshakes in a group of people. This is given by the formula n*(n-1)/2, where n is the number of people. The program then takes the input n and checks if it is valid (between 1 and 500). If it's not valid, it outputs an error message and terminates. Otherwise, it outputs the number of handshakes.