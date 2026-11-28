#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1 || n > 100000) {
        cout << "Invalid input, please enter a positive integer between 1 and 100000." << endl;
        return 0;
    }

    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    cout << "The binary representation is: " << binary << endl;

    return 0;
}