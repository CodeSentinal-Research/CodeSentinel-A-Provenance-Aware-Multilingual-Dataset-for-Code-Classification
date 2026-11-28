Here is the complete C++ code:

#include <iostream>
using namespace std;

int main() {
    double length, breadth, height, volume;

    cout << "Enter length, breadth and height: ";
    cin >> length >> breadth >> height;

    if(length <= 0 || breadth <= 0 || height <= 0 || length > 100 || breadth > 100 || height > 100) {
        cout << "Invalid input, dimensions should be in range 1-100.";
        return 0;
    }

    volume = length * breadth * height;
    cout << "Volume of cuboid is: " << volume;

    return 0;
}

This program will first prompt the user to input the dimensions of the cuboid. It then checks if the dimensions are valid (i.e., between 1 and 100). If the dimensions are valid, it will calculate the volume of the cuboid and print it out. Otherwise, it will print out an error message.