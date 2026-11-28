#include <iostream>

using namespace std;

int main() {
    double r;
    cout << "Enter the radius of the sphere: ";
    cin >> r;
    if (r >= 0 && r <= 50) {
        double volume = (4.0/3.0) * 3.14159 * (r*r*r);
        cout << "The volume of the sphere is: " << volume;
    } else {
        cout << "Invalid input";
    }
    return 0;
}