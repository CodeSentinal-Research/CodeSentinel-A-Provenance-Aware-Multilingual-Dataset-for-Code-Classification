#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i))
            count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n >= 1 && n <= 10000000) {
        cout << "Count of prime numbers less than or equal to " << n << ": " << countPrimes(n) << endl;
    } else {
        cout << "Input out of range" << endl;
    }
    return 0;
}