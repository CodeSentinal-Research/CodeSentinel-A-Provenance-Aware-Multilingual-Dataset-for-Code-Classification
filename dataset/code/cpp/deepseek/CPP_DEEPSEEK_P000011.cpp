#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    if (a > b) {
        if (a > c) {
            cout << "The maximum is: " << a;
        } else {
            cout << "The maximum is: " << c;
        }
    } else {
        if (b > c) {
            cout << "The maximum is: " << b;
        } else {
            cout << "The maximum is: " << c;
        }
    }
    return 0;
}