Sure, here is the code:

#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int L, R;
    cout << "Enter two positive integers: ";
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}

In this code, the function `isPrime(int num)` checks whether a number is prime. It does this by checking divisibility with all numbers up to the square root of the number. If any of these divisors result in a remainder of zero (i.e., the number is divisible), then it is not a prime number.

In the `main` function, we read the two integers from the user and then loop through all the numbers between L and R (inclusive). If a number is prime (checked by calling `isPrime(i)`), we print it.