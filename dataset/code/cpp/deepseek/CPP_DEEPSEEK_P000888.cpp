Here's the C++ code for the problem:

#include <iostream>
#include <cmath>
using namespace std;

bool isAutomorphic(long long N) {
    long long square = N * N;
    long long lastDigit = square % 10;

    while (square > 9) {
        square /= 10;
    }

    return square == N;
}

int main() {
    long long N;
    cout << "Enter a number: ";
    cin >> N;

    if (isAutomorphic(N)) {
        cout << "Automorphic number\n";
    } else {
        cout << "Not an Automorphic number\n";
    }

    return 0;
}

This program first takes an input N, then checks if N is an Automorphic number using the function `isAutomorphic`. It calculates the square of N and gets the last digit of the square. Then, it continues dividing the square by 10 until it becomes less than 10 (which only happens when N is a 1-digit number). If the square is equal to N, then N is an Automorphic number. Otherwise, it is not.