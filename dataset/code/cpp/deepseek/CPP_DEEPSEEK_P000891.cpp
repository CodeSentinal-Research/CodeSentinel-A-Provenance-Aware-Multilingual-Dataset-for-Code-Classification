Here is the C++ code:

#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int nextPrime(int num) {
    if (num <= 1) return 2;
    if (num ==2) return 3;
    int next = num;
    bool found = false;
    while (!found) {
        next++;
        if (isPrime(next))
            found = true;
    }
    return next;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "The next prime number is: " << nextPrime(num) << endl;
    return 0;
}

This code will take an integer as input and output the next prime number that is greater than the given integer. The `isPrime` function checks if a number is prime, and the `nextPrime` function checks each number starting from the input number to find the next prime number.