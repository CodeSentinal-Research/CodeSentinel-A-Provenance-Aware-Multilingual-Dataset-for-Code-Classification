Here is the C++ code for the problem:

#include <iostream>
using namespace std;

void printLexicographical(int n) {
    if (n == 0) {
        return;
    }
    printLexicographical(n / 10);
    cout << n % 10 << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 10) {
        cout << "The number must be at least 10";
        return 0;
    }
    printLexicographical(n);
    return 0;
}

In this code, the function `printLexicographical(int n)` is recursively called to print all numbers from 1 to `n` in lexicographical order.

In `main()`, the user is asked to enter a number. If the entered number is less than 10, it will print a message to the user that the number must be at least 10.

The base case is when `n` is less than 10 (when `n` is 0), the recursion stops. Otherwise, the function calls itself with `n / 10` (the integer part of `n` divided by 10) and `n % 10` (the last digit of `n`). The last digit `n % 10` is printed and then the function calls itself with the integer part `n / 10` until it reaches the base case.