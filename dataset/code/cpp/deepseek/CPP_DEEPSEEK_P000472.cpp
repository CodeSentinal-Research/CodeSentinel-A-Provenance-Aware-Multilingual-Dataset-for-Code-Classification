Here's the C++ code to find the peak element in a 2D matrix:

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int max = matrix[0][0];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    cout << max;

    return 0;
}
This code takes the number of rows and columns as input, creates a 2D array (matrix) to store the input, and finds the maximum value in the matrix. The maximum value is then printed out.