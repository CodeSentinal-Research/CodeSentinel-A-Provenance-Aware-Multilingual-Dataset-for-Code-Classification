#include <iostream>
using namespace std;

int modularMultiplicativeInverse(int A, int M) {
    if (__gcd(A, M) != 1) {
        return -1;
    }
    return (A % M == 0) ? -1 : ((A - (A / M) * M) + 1);
}

int main() {
    int A, M;
    cout << "Enter A and M: ";
    cin >> A >> M;
    cout << "Modular Multiplicative Inverse is: " << modularMultiplicativeInverse(A, M) << endl;
    return 0;
}
This code first checks if the greatest common divisor (gcd) of A and M is not 1. If it is not 1, it means that A and M share no common factors other than 1, so no modular multiplicative inverse exists. If the gcd is 1, it means that A and M share a factor that is not 1, so a modular multiplicative inverse exists.

If the gcd is 1, it computes the modular multiplicative inverse of A modulo M using the formula: ((A - (A / M) * M) + 1) % M.

The condition (A - (A / M) * M) % M ensures that the result is always non-negative. If the result is 0, it means that A / M is a multiple of M, so there is no modular multiplicative inverse.

In the main function, the code reads the values of A and M from the user, calls the modularMultiplicativeInverse function with these values, and prints the result.