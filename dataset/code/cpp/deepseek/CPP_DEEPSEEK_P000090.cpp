Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    long long result = 1;
    for(int i = 1; i <= r; i++) {
        result = result * (n - i + 1);
        result = result / i;
    }

    cout << "nCr = " << result << endl;
    return 0;
}
This program uses the formula for binomial coefficient nCr: nCr = n! / (r!(n-r)!)
where '!' denotes factorial. It asks the user to enter the value of n and r, calculates nCr using the formula, and then prints the result.