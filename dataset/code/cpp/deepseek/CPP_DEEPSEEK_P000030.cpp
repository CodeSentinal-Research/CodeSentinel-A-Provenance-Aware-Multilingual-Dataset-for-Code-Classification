#include <iostream>

using namespace std;

int LCM(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int remainder = a % b;

    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }

    return b;
}

int main() {
    int a, b;

    cout << "Enter two positive integers: ";
    cin >> a >> b;

    cout << "The LCM of " << a << " and " << b << " is " << LCM(a, b) << endl;

    return 0;
}