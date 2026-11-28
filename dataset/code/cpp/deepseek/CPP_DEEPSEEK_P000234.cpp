Here is the C++ code that meets the given requirements:

#include <iostream>

using namespace std;

void modifyMatrix(bool matrix[50][50], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = true;
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    bool matrix[50][50];

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = false;
        }
    }

    modifyMatrix(matrix, rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}

This program first takes the number of rows and columns from the input. It then creates a boolean matrix of the given size and initializes it with all false. The `modifyMatrix` function then sets all elements in the matrix to true. Finally, it prints the modified matrix.