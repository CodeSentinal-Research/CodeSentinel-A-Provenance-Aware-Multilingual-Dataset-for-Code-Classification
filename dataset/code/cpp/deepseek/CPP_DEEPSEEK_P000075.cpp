#include <iostream>
using namespace std;

int main() {
    double r, h, volume;

    cout << "Enter the radius of the cylinder: ";
    cin >> r;

    cout << "Enter the height of the cylinder: ";
    cin >> h;

    volume = M_PI * r * r * h;

    cout << "The volume of the cylinder is: " << volume << endl;

    return 0;
}