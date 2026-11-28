Here is the code:

#include <iostream>
using namespace std;

int N;
int mat[5][5];

int determinant() {
    if (N == 1)
        return mat[0][0];
    else {
        int sum = 0;
        int sign = 1;
        for (int i = 0; i < N; i++) {
            int a[5][5];
            int sub = 0;
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++ {
                    if (j != i)
                        a[j][k] = mat[j][(k + sign) % N];
                    else
                        a[j][k] = mat[j][(k + sign + 1) % N];
                    sub += a[j][k] * ((j + i + sign) % 2 ? 1 : -1) * fact(N);
                }
            }
            sum += sub * fact(N - 1);
            sign *= -1;
        }
        return sum;
    }
}

int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
    cout << determinant();
    return 0;
}

This code calculates the determinant of a square matrix using the formula for the determinant of a matrix which is the product of the minor matrix determinants (for all possible swaps of rows). The `fact` function calculates the factorial of a number. The `main` function reads the matrix from standard input, calls the `determinant` function to calculate the determinant, and then prints the result. The swapping of rows is done using the `sign` variable. If the row index is even, then the sign is -1, otherwise it is 1.