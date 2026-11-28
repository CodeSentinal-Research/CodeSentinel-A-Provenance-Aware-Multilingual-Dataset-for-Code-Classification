Here is the C++ code that solves the problem:

#include <iostream>

using namespace std;

int sumNaturalNumbers(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sumNaturalNumbers(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    if (n < 1 || n > 100000) {
        cout << "Invalid input. Please enter a number between 1 and 10^5.";
        return 1;
    }
    cout << "The sum of the first " << n << " natural numbers is: " << sumNaturalNumbers(n);
    return 0;
}

This program uses recursion to calculate the sum of the first N natural numbers. The `sumNaturalNumbers` function takes an integer `n` as input and returns the sum of the first `n` natural numbers. If `n` is 1, it returns 1, otherwise it returns `n` plus the sum of the first `n - 1` natural numbers.

The `main` function handles the input and outputs the result. It first prompts the user for an integer input, then checks if the input is valid (between 1 and 10^5). If the input is valid, it calculates and prints the sum of the first `n` natural numbers. If the input is not valid, it prints an error message.