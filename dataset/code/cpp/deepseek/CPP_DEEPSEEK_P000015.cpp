#include <iostream>
using namespace std;

int main() {
    double length, breadth, perimeter;

    cout << "Enter length of rectangle: ";
    cin >> length;

    cout << "Enter breadth of rectangle: ";
    cin >> breadth;

    perimeter = 2 * (length + breadth);

    cout << "Perimeter of rectangle is: " << perimeter << endl;

    return 0;
}