Here is the C++ code:

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    if(a % b == 0) {
        cout << "Divisible";
    } else {
        cout << "Not Divisible";
    }

    return 0;
}

In this code, we are first taking two integers as input from the user. Then we are checking if the first number is divisible by the second number (a % b == 0). If it is, we print "Divisible", otherwise we print "Not Divisible".