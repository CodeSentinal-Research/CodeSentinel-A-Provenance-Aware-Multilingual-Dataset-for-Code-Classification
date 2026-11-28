#include <iostream>
using namespace std;

int main() {
    int days;
    cout << "Enter a positive integer days: ";
    cin >> days;

    int years = days / 365;
    days %= 365;

    int weeks = days / 7;
    days %= 7;

    cout << "Years: " << years << endl;
    cout << "Weeks: " << weeks << endl;
    cout << "Days: " << days << endl;

    return 0;
}