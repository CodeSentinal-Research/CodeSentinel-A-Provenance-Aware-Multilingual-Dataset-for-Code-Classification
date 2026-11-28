#include <iostream>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    int matrix[row][col], sum, maxSum = INT_MIN;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            sum = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2] +
                  matrix[i+1][j+1] +
                  matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2];

            if(sum > maxSum)
                maxSum = sum;
        }
    }

    cout << maxSum;
    return 0;
}