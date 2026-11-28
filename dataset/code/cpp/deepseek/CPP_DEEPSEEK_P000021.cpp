Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Error! Factorial of a negative number doesn't exist.";
    } else {
        cout << "Factorial of " << n << " = " << factorial(n);
    }

    return 0;
}

This program takes an input integer from the user and prints the factorial of that number using recursion. If the input number is less than 0, it prints an error message.