Here is a simple C++ code snippet that rotates a matrix in clockwise direction by one step.

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[rows][cols];

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            cin >> matrix[i][j];

    for(int i=0; i<rows; i++)
        for(int j=i; j<cols; j++)
            swap(matrix[i][j], matrix[j][i]);

    for(int i=0; i<rows; i++)
        for(int j=0, k=cols-1; j<k; j++, k--)
            swap(matrix[i][j], matrix[i][k]);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

This code first reads the rows and columns of the matrix, then it reads the matrix itself. It then performs the following operations:

1. Transposes the matrix. This means swapping the elements of the matrix with the ones on the main diagonal.
2. Reverses each row. This means swapping the first element with the last, the second element with the second last, and so on.

Finally, it prints the rotated matrix.