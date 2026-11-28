#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 0 && age <= 120) {
        if (age >= 18) {
            cout << "Eligible";
        } else {
            cout << "Not Eligible";
        }
    } else {
        cout << "Invalid age. Please enter a valid age between 0 and 120.";
    }

    return 0;
}