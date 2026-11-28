Here's the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < rows; i++) {
        if(i % 2 == 0) { 
            for(int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
        } else { 
            for(int j = cols - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

This program reads the number of rows and columns from the input, then reads the matrix from the input. It then prints the elements of the matrix in a zigzag pattern (from left to right for the first row, then right to left for the next rows). The output for each row is printed on a new line.