Here is the required C++ code:

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Even";
    } else {
        cout << "Odd";
    }

    return 0;
}

This code will prompt the user to enter an integer. Then, it will check if the entered integer is even or odd. The result is printed out to the console.