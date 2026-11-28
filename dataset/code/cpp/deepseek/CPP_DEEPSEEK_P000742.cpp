Here is the C++ code that solves the problem:

#include <iostream>
using namespace std;

void printNumbers(int n, int current = 1) {
    if(current > n) {
        return;
    }
    cout << current << endl;
    printNumbers(n, current + 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printNumbers(n);
    return 0;
}

In this code, we are using a recursive function `printNumbers` which prints numbers from 1 to `n`. The function takes two parameters: `n` (the number to print to) and `current` (the current number being printed. Default is 1). If `current` is greater than `n`, the function returns. Otherwise, it prints `current` and calls itself with `current + 1`.

In the `main` function, we ask the user for an input and then call the `printNumbers` function with the input.