Here is a simple C++ program that takes an input matrix from the user, performs a spiral order traversal on it and prints the result.

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
    
    while(rows > 0 && cols > 0) {
        for(int i = 0; i < cols; i++) {
            cout << matrix[0][i] << " ";
        }
        matrix.erase(matrix.begin());
        rows--;
        
        if(rows > 0) {
            for(int i = 0; i < rows; i++) {
                cout << matrix[i][cols-1] << " ";
            }
            for(int i = 0; i < rows; i++) {
                matrix[i].pop_back();
            }
        }
        cols--;
        
        if(cols > 0) {
            for(int i = cols-1; i >= 0; i--) {
                cout << matrix[rows-1][i] << " ";
            }
            matrix.pop_back();
            rows--;
        }
        
        if(rows > 0) {
            for(int i = rows-1; i >= 0; i--) {
                cout << matrix[i][0] << " ";
            }
            for(int i = 0; i < rows; i++) {
                matrix[i].erase(matrix[i].begin());
            }
        }
    }
    
    return 0;
}

This program first reads the number of rows and columns from the input. Then it reads the matrix from the input. After that, it performs a spiral order traversal on the matrix and prints the result.