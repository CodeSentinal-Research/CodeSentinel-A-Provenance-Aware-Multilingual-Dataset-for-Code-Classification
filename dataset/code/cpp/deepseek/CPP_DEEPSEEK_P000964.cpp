Here is the C++ code for the Chinese Remainder Theorem Solver:

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findModInverse(int a, int m) {
    for (int i = 1; i <= a; i++)
        if ((a % m) == 0 && (m % i == 0) && (gcd(i, m) == 1))
            return i;
    return -1;
}

int findX(int remainder[], int modulus[], int N) {
    int prod_mod = 1;
    for (int i = 0; i < N; i++)
        prod_mod *= modulus[i];

    int x = 0;
    for (int i = 0; i < N; i++) {
        int tmp = prod_mod / modulus[i];
        x += remainder[i] * tmp * findModInverse(tmp, modulus[i]);
        x %= prod_mod;
    }
    return x % prod_mod;
}

int main() {
    int N;
    cin >> N;
    int modulus[N], remainder[N];
    for (int i = 0; i < N; i++)
        cin >> modulus[i] >> remainder[i];
    cout << findX(remainder, modulus, N);
    return 0;
}

In this code, the `gcd` function finds the greatest common divisor of two numbers. The `findModInverse` function finds the modular multiplicative inverse of a number modulo another number. The `findX` function calculates the smallest non-negative integer that satisfies all congruences. It calculates the product of all moduli, then it calculates the modular multiplicative inverse of each modulus. Finally, it calculates the result and returns it modulo the product of all moduli.