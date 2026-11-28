Here is the C++ code that solves the problem:

#include <iostream>
using namespace std;

long long powMod(long long a, long long b, long long m) {
    if (b == 0)
        return 1;
    long long x = powMod(a, b / 2, m);
    if (b % 2 == 0)
        return (x * x) % m;
    else
        return (((x * x) % m) * a) % m;
}

int main() {
    long long A, N;
    cin >> A >> N;
    cout << powMod(A, N, N);
    return 0;
}

This code first declares the function powMod which computes A^N mod N using recursive calls. This is based on the Euler's Theorem, which states that a^(φ(N)) ≡ 1 (mod N) for all integers N.

In the main function, it takes A and N as inputs, calls the powMod function with A, N, and N as arguments, and then prints the returned value.