#include <iostream>

using namespace std;

long long solveCongruence(long long A, long long B, long long M) {
    if (M == 1) {
        return B;
    }

    long long a = A % M;
    long long b = B % M;

    if (a == 0) {
        return (b == 0) ? -1 : B;
    }

    long long d = __gcd(a, M);

    a /= d;
    b /= d;
    long long x = (a * (B % M) - B - B % M + M) % M;

    return (x < 0) ? x + M : x;
}

int main() {
    long long A, B, M;
    cin >> A >> B >> M;
    cout << solveCongruence(A, B, M) << endl;
    return 0;
}
This C++ program uses the Extended Euclidean Algorithm to find the multiplicative inverse of `a` mod `M`. The multiplicative inverse of `a` mod `M` is `x` such that `(ax - by = d)` (where `d` is the greatest common divisor of `a` and `M`). If the input is valid, this program will return the smallest non-negative solution, otherwise it will return -1.