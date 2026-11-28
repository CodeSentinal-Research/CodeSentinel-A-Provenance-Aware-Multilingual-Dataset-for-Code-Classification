Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter an integer: ";
    cin >> N;

    if ((N & 1) == 0) {
        cout << "Even";
    } else {
        cout << "Odd";
    }

    return 0;
}

In this code, the bitwise operator & is used to check if the least significant bit of the integer is 0 or 1. If it is 0, then the number is even, otherwise it is odd.