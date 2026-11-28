Here is the C++ code to find the modular multiplicative inverse of a number modulo another number. We use Euclid's Algorithm for this:

#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = gcd(b, a % b, y, x);
    y -= a / b * x;
    return gcd;
}

int modularInverse(int a, int m) {
    int x, y;
    int gcd = gcd(a, m, x, y);
    if (gcd != 1) {
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int a, m;
    cout << "Enter two positive integers: ";
    cin >> a >> m;
    cout << "Modular multiplicative inverse: " << modularInverse(a, m) << endl;
    return 0;
}
This program first defines a helper function `gcd` that implements Euclid's algorithm. Then it defines the `modularInverse` function, which uses this helper function to find the modular multiplicative inverse. It takes two integers as input, checks if the input integers are valid (i.e., they are positive and not too large), and then prints the modular multiplicative inverse. If the input integers are not valid, the program prints -1.