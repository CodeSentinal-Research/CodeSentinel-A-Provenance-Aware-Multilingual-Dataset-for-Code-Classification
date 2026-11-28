#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[rows][cols], transposed[cols][rows];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

This C++ program reads the number of rows and columns from the standard input, then reads the matrix. It then transposes the matrix and prints the transposed matrix to the standard output.