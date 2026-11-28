Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(i==0 || i==rows-1 || j==0 || j==cols-1) {
                sum += matrix[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}

This code reads the matrix dimensions and then the matrix itself. It then calculates the sum of the boundary elements of the matrix. The boundary elements are the first and last row and column of the matrix.