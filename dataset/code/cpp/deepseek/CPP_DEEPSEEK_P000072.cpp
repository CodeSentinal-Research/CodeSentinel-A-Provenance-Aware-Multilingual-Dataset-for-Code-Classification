#include <iostream>
using namespace std;

int main() {
    double side;
    cout << "Enter side length of cube: ";
    cin >> side;

    if(side < 1 || side > 100) {
        cout << "Invalid input. Please enter a number between 1 and 100.";
        return 0;
    }

    double volume = side * side * side;
    cout << "Volume of the cube is: " << volume;
    return 0;
}