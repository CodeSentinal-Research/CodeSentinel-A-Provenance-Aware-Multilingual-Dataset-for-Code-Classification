Here's the required C++ code:

#include <iostream>
using namespace std;

int main() {
    double a, r, n;
    cout << "Enter first term: ";
    cin >> a;
    cout << "Enter common ratio: ";
    cin >> r;
    cout << "Enter number of terms: ";
    cin >> n;

    double sum = a * (1 - r) / (1 - r ^ n);

    cout << "The sum of the GP series is: " << sum << endl;

    return 0;
}

This code will prompt the user to enter the first term, common ratio, and the number of terms. It will then calculate the sum of the geometric progression series using the formula for the sum of a geometric series, which is a^n / (1 - a) where a is the first term, r is the common ratio, and n is the number of terms.