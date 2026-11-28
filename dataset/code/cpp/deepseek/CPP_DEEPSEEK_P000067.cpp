#include <iostream>
using namespace std;

int main() {
    double side;
    cout << "Enter side length of the square: ";
    cin >> side;

    if (side < 1 || side > 1000) {
        cout << "Invalid input. Please enter a number between 1 and 1000." << endl;
        return 1;
    }

    double area = side * side;
    cout << "The area of the square is: " << area << endl;

    return 0;
}