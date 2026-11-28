Here is a simple solution to the problem. It uses the method of quadratic formula to find the solutions.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    long long discriminant = B * B - 4 * A * C;

    if (discriminant < 0) {
        cout << -1;
        return 0;
    }

    long double sol1 = (-B + sqrt(discriminant)) / (2 * A);
    long double sol2 = (-B - sqrt(discriminant)) / (2 * A);

    cout << sol1 << " " << sol2;

    return 0;
}
This program first calculates the discriminant of the quadratic equation. If the discriminant is less than zero, it means there is no solution, and the program outputs -1. If the discriminant is greater than or equal to zero, it calculates the two solutions using the quadratic formula and prints them.