Here is the complete C++ code:

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int sqrt = sqrt(n);
    if (sqrt*sqrt == n) {
        cout << "Perfect Square";
    } else {
        cout << "Not Perfect Square";
    }

    return 0;
}

This program first takes an input number `n` from the user. Then, it calculates the square root of `n` using the `sqrt` function from the `cmath` library. If the square of the square root equals `n`, it means `n` is a perfect square, otherwise it's not. The result is then printed out.