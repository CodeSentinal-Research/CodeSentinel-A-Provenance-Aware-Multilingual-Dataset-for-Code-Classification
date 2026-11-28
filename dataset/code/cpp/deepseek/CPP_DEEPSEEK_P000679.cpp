Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

void printNumbers(int n) {
    if(n > 0) {
        cout << n << " ";
        printNumbers(n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    printNumbers(n);
    return 0;
}
This program uses recursion to print all the integers from 1 to N. The `printNumbers` function is a recursive function that takes an integer `n` as input and prints the integer. It first checks if `n` is greater than 0. If `n` is greater than 0, it prints the current number (n) and then calls itself with the argument `n - 1`. This process continues until `n` becomes 0, at which point the recursion stops.