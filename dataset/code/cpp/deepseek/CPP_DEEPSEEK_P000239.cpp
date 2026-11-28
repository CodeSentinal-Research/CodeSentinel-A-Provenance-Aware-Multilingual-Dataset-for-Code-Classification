#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int mat[rows][cols];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        cout << mat[i][0] << " ";
        cout << mat[i][cols-1] << " ";
    }
    for(int j = 0; j < cols; j++) {
        cout << mat[0][j] << " ";
        cout << mat[rows-1][j] << " ";
    }

    return 0;
}
This program reads a matrix of size N x M (where N and M are provided as inputs), and then prints all boundary elements of the matrix. The boundary elements are considered to be the first and last element of each row and column.