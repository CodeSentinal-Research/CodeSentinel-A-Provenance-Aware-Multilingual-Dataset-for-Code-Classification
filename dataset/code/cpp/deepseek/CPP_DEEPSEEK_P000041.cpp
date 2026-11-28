#include <iostream>
using namespace std;

int main() {
    float a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    float avg = (a + b + c) / 3;
    cout << "The average of " << a << ", " << b << ", and " << c << " is: " << avg;
    return 0;
}