Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    if(a > b) {
        if(a > c) {
            cout << "The largest number is: " << a;
        } else {
            cout << "The largest number is: " << c;
        }
    } else {
        if(b > c) {
            cout << "The largest number is: " << b;
        } else {
            cout << "The largest number is: " << c;
        }
    }

    return 0;
}
This program will first prompt the user to enter three integers. It then uses nested if statements to find and print the largest number among the three.