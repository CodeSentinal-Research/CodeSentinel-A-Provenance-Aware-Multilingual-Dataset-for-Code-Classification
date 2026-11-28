#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int firstMatrix[rows][cols], secondMatrix[rows][cols], result[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> firstMatrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> secondMatrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
This code first reads in the dimensions of the matrices, then it reads in the matrices themselves. The sum of the two matrices is then calculated and printed. The main difference between the given problem and this code is that this code directly prints the sum, while the given problem asks to input the matrices and print the sum.