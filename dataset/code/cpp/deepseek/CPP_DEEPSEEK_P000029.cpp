#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}