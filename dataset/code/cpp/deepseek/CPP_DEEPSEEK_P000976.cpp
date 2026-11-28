Here is the complete C++ code for the given problem:

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter the coordinates of the first vertex: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second vertex: ";
    cin >> x2 >> y2;
    cout << "Enter the coordinates of the third vertex: ";
    cin >> x3 >> y3;

    double area = 0.5 * abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));

    cout << "The area of the triangle is " << area << endl;

    return 0;
}
In this code, we first read the coordinates of the three vertices from the user. Then, we calculate the area of the triangle using the formula:

area = 0.5 * abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
This formula is derived from the geometric principle that the area of a triangle can be calculated using the formula:

area = 0.5 * abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));

In this formula, `x1 * (y2 - y3)`, `x2 * (y3 - y1)`, and `x3 * (y1 - y2)` are the cross products of the vectors from the triangle's vertex to the other two vertices. These cross products represent the areas of the triangle.

Finally, the area is printed to the console.