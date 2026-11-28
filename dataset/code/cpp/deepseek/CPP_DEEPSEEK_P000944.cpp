Here is the C++ code for the problem:

#include <iostream>
using namespace std;

bool divisor_game(int N) {
    if (N % 2 == 0) {
        return true;
    }

    if (N % 3 == 0 || N % 3 == 1) {
        return true;
    }

    if (N % 4 == 0 || N % 4 == 1) {
        return true;
    }

    return false;
}

int main() {
    int N;
    cout << "Enter an integer: ";
    cin >> N;
    if (divisor_game(N)) {
        cout << "Player 1 wins";
    } else {
        cout << "Player 2 wins";
    }
    return 0;
}

This code uses a simple algorithm to check if the first player will win. If N is divisible by 2, then player 1 will lose, if N is divisible by 3 or 3-modulo N is 0, then player 1 will lose, if N is divisible by 4 or 4-modulo N is 0, then player 1 will lose, otherwise player 1 will win.