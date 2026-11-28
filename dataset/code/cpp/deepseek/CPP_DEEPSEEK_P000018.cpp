#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if(year >= 1 && year <= 9999) {
        if(year % 4 == 0) {
            if(year % 100 == 0) {
                if(year % 400 == 0) 
                    cout << "Leap Year";
                else
                    cout << "Not a Leap Year";
            } else
                cout << "Leap Year";
        } else
            cout << "Not a Leap Year";
    } else {
        cout << "Invalid input. Please enter a year between 1 and 9999.";
    }

    return 0;
}