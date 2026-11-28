Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int phi(int n) {
    int result = 1;
    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1 || n > 1000000000) {
        cout << "Invalid input. Please enter a positive integer between 1 and 10^12." << endl;
        return 0;
    }

    cout << "The value of φ(" << n << ") is " << phi(n) << endl;
    return 0;
}

This code defines a function to calculate the gcd (Greatest Common Divisor) of two numbers. Then, it calculates the phi (Euler's Totient Function) of a given number by iterating through all numbers less than the given number and checking if the number and the given number are coprime (have a 1 as the gcd). If they are, it increments the result.

In the main function, it takes an input for the number and checks if it's valid (i.e., between 1 and 10^12). If not, it outputs an error message and terminates. Otherwise, it calculates and prints the phi of the given number.