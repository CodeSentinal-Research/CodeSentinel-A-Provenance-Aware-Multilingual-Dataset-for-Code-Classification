#include <iostream>
using namespace std;

int main() {
    double a, b, c;

    cout << "Enter three positive numbers a, b, c: ";
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Invalid";
    } else {
        cout << "Valid";
    }

    return 0;
}