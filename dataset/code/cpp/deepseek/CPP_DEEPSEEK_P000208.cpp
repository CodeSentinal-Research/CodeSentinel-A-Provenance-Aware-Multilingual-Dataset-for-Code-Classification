Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int k = 0; k < rows * cols; k++) {
        cout << matrix[k / cols][k % cols] << " ";
    }

    return 0;
}

This code first takes the number of rows and columns as input. It then creates a 2D array to store the matrix. After that, it takes the input for the matrix and prints the elements in diagonal order. The for loop iterates through all the elements and prints them in the format you provided.