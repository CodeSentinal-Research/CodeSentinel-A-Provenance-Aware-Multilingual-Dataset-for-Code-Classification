Here is the C++ solution for the given problem:

#include <iostream>
using namespace std;

int add(int a, int b) {
    while(b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    int sum = add(a, b);
    cout << "The sum is: " << sum << endl;
    return 0;
}

This program uses bitwise operators to implement the addition of two numbers without using arithmetic operators.