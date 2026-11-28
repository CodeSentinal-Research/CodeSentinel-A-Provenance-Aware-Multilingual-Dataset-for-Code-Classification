#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPrime(n)) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}
This C++ code defines a function `isPrime(int n)` to check if a number is prime. This function first handles the special cases (less than or equal to 1 or equal to 2), then it checks if the number is divisible by 2 (if it is, it's not a prime number), and finally, it checks for divisors up to the square root of the number.

In the `main()` function, the user is asked to input a number, and the prime check is performed using the `isPrime(n)` function. The result is printed out.