#include <iostream>
using namespace std;

long long power(long long x, long long y, long long m) {
    if (y == 0)
        return 1;

    long long p = power(x, y / 2, m);
    if (y % 2 == 0)
        return (p * p) % m;
    else
        return (((p * p) % m) * x) % m;
}

int main() {
    long long base, exponent, mod;
    cout << "Enter base exponent mod: ";
    cin >> base >> exponent >> mod;
    cout << "Result: " << power(base, exponent, mod) << endl;
    return 0;
}
This code first handles the base case when the exponent is 0, then it uses the formula (x^y) mod m = ((x mod m)^y) mod m. It also uses long long for the computation to handle large numbers. The power function recursively calls itself until the exponent is 0, then it returns 1. If the exponent is odd, it computes (x^(y/2)) mod m, multiplies it by x if the exponent is odd and then computes ((x mod m)^(y/2)) mod m.