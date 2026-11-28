#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n >= 1 && n <= 20) {
        for (int i = 1; i <= 10; i++) {
            cout << n << " * " << i << " = " << n*i << endl;
        }
    } else {
        cout << "Invalid input. Please enter a positive integer between 1 and 20." << endl;
    }

    return 0;
}