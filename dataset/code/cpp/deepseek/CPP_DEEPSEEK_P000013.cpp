#include <iostream>
using namespace std;

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    if (r >= 0 && r <= 100) {
        double area = 3.14159 * r * r;
        cout << "The area of the circle is: " << area << endl;
    } else {
        cout << "Invalid input. The radius should be between 0 and 100." << endl;
    }
    return 0;
}