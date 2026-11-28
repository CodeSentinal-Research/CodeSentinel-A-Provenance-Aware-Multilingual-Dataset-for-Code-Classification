Here is the complete C++ code:

#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three positive numbers: ";
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "Equilateral";
    } else if (a == b || b == c || a == c) {
        cout << "Isosceles";
    } else {
        cout << "Scalene";
    }

    return 0;
}

In this code, we first get the three sides from the user. Then, we check if the sides form a valid triangle according to the triangle inequality theorem (the sum of the lengths of any two sides of a triangle must be greater than the length of the third side). If they do, we print the type of the triangle, otherwise, we print "Scalene".