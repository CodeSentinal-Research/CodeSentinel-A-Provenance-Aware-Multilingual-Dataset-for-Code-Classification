#include <iostream>
using namespace std;

int main() {
    int units;
    cout << "Enter number of units consumed: ";
    cin >> units;

    double billAmount = 0;

    if (units <= 50) {
        billAmount = units * 0.5;
    }
    else if (units <= 100) {
        billAmount = 25 + ((units - 50) * 0.75);
    }
    else if (units <= 200) {
        billAmount = 125 + ((units - 100) * 1.20);
    }
    else {
        billAmount = 275 + ((units - 200) * 1.50);
    }

    cout << "Total bill amount: " << billAmount << endl;

    return 0;
}