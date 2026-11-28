#include <iostream>
using namespace std;

int main() {
    int x, n;
    cout << "Enter a base number: ";
    cin >> x;
    cout << "Enter an exponent: ";
    cin >> n;
    cout << x << "^" << n << " = " << pow(x, n) << endl;
    return 0;
}