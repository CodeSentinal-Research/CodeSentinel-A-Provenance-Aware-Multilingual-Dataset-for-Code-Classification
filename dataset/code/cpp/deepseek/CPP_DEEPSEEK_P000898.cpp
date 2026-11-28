Here is the C++ code:

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> reduceFraction(int numerator, int denominator) {
    int gcd_num_denom = gcd(numerator, denominator);
    int reduced_numerator = numerator / gcd_num_denom;
    int reduced_denominator = denominator / gcd_num_denom;
    return {reduced_numerator, reduced_denominator};
}

int main() {
    int numerator, denominator;
    cout << "Enter numerator and denominator: ";
    cin >> numerator >> denominator;
    pair<int, int> reduced = reduceFraction(numerator, denominator);
    cout << "Reduced fraction: " << reduced.first << "/" << reduced.second << endl;
    return 0;
}

This program first gets the numerator and denominator of the fraction from the user. Then, it calls the `reduceFraction` function to reduce the fraction to its lowest terms. The `reduceFraction` function uses the Euclidean algorithm to find the greatest common divisor (gcd) of the numerator and denominator, and then divides both the numerator and denominator by this gcd to get the reduced fraction. The result is then printed out.