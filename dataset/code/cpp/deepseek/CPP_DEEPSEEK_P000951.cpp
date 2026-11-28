Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += __gcd(i, N);
    }

    cout << "Sum of Totient values from 1 to N is: " << sum << endl;

    return 0;
}
This code uses Euler's Totient Function formula (φ(n) is the count of positive integers less than or equal to n which are co-prime to n) to calculate the sum of the totient values from 1 to N. The gcd function from the Standard Template Library (STL) is used to calculate the greatest common divisor (gcd) of two integers. The sum is accumulated in the variable sum.