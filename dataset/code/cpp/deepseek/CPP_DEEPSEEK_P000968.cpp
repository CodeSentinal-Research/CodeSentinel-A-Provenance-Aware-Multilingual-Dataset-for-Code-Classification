Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(int a, int m, int b, int n) {
    int d = gcd(m, n);

    if ((a % d) == (b % d)) {
        return (a / d) % m;
    }

    return -1;
}

int main() {
    int a, m, b, n;

    cin >> a >> m >> b >> n;

    int solution = solve(a, m, b, n);

    if (solution != -1) {
        cout << "The solution is: " << solution << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

This program first finds the greatest common divisor (gcd) of the moduli. If the congruences `X ≡ A (mod M)` and `X ≡ B (mod N)` can be merged, then the program will output the solution. Otherwise, it will output a message saying that no solution exists.