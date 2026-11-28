Here is the C++ code that solves the problem:

#include <iostream>
#include <cmath>

using namespace std;

enum class TriangleType {
    Equilateral,
    Isosceles,
    Scalene,
    NotATriangle
};

TriangleType determineTriangleType(double x1, double y1, double x2, double y2, double x3, double y3) {
    double area1 = abs(0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
    double area2 = abs(0.5 * (x1*(y3-y2) + x2*(y1-y3) + x3*(y2-y1)));
    double area3 = abs(0.5 * (x2*(y1-y3) + x3*(y2-y1) + x1*(y3-y2)));

    if (area1 == area2 && area2 == area3) {
        if (area1 == 0) {
            return TriangleType::NotATriangle;
        } else {
            return TriangleType::Equilateral;
        }
    }

    return TriangleType::NotATriangle;
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter the coordinates of the three points: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    TriangleType type = determineTriangleType(x1, y1, x2, y2, x3, y3);

    switch (type) {
        case TriangleType::Equilateral:
            cout << "The triangle is equilateral.";
            break;
        case TriangleType::Isosceles:
            cout << "The triangle is isosceles.";
            break;
        case TriangleType::Scalene:
            cout << "The triangle is scalene.";
            break;
        case TriangleType::NotATriangle:
            cout << "The points do not form a triangle.";
            break;
    }

    return 0;
}

This code first calculates the areas of three triangles formed by the three points. Then it checks if the areas of all triangles are the same. If they are, it checks if the area of the triangle is zero (in which case it is a point, so it's not a triangle). If not, it determines that the points do not form a triangle. If the areas are not the same, it determines that the points do not form a triangle.