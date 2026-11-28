Here is the C++ code for the Extended Euclidean Algorithm:

#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

int main() {
    int a, b, x, y, gcd;
    cout << "Enter two numbers (A and B): ";
    cin >> a >> b;
    gcd = gcd(a, b, x, y);
    cout << "The gcd of " << a << " and " << b << " is " << gcd << endl;
    cout << "The values are X = " << x << " and Y = " << y << endl;
    return 0;
}

This code will ask for input two numbers, then use the extended euclidean algorithm to calculate the greatest common divisor (gcd) and the values of x and y that satisfy the equation AX + BY = gcd(A, B).