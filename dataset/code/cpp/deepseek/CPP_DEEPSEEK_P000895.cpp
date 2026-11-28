Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}

In this code, we first define a function `gcd` that calculates the greatest common divisor of two numbers. Then we define a function `lcm` that uses the formula `lcm(a, b) = (a * b) / gcd(a, b)` to calculate the least common multiple. The `main` function reads two integers from the standard input, calls the `lcm` function with these two numbers, and prints the result.