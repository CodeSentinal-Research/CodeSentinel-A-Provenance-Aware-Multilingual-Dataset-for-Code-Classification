#include <iostream>
using namespace std;

int main() {
    float r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    if(r >= 0 && r <= 100) {
        float c = 2 * 3.14159 * r;
        cout << "The circumference of the circle is: " << c << endl;
    }
    else {
        cout << "Invalid input. Radius should be between 0 and 100." << endl;
    }
    return 0;
}