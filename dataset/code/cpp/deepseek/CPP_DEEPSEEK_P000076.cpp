Here is the complete C++ code for the problem:

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Enter values for a, b, c:" << endl;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different: " << root1 << " and " << root2 << endl;
    } else if (discriminant == 0) {
        double root1 = -b / (2 * a);
        cout << "Roots are real and equal: " << root1 << endl;
    } else {
        cout << "Roots are complex." << endl;
    }

    return 0;
}

This program takes the coefficients a, b, and c as input and calculates the discriminant of the quadratic equation. Depending on the discriminant, it calculates and prints the roots of the equation.