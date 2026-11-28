#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int sumOfPrimes(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            sum += i;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n <= 0 || n > 10000) {
        cout << "Invalid input. Please enter a positive integer between 1 and 10000.";
        return 0;
    }
    cout << "Sum of primes up to " << n << " is: " << sumOfPrimes(n);
    return 0;
}