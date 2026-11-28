Here's the code for the given problem:

#include <iostream>
using namespace std;

int main() {
    int n, r;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of r: ";
    cin >> r;

    int C[r+1][r+1];

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= min(i, r); ++j) {
            if(j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    cout << "Binomial Coefficient " << n << "C" << r << " = " << C[n][r];
    return 0;
}

This C++ code implements the binomial coefficient computation using a 2D dynamic programming approach. The 2D array C stores the binomial coefficients for all possible values of n and r. The main logic is in the innermost loop where we fill up the C array. For each value of n, we calculate the binomial coefficient C[n][r] by adding up the binomial coefficients C[n-1][r] and C[n-1][r-1]. The base cases are C[i][0] = 1 and C[i][i] = 1 for all i.