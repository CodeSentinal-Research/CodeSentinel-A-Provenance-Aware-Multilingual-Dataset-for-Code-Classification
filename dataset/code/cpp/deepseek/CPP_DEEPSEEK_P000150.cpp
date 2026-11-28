Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    sort(matrix.begin(), matrix.end());

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

This program reads the number of rows and columns from the input, then reads the matrix elements. The sorted matrix is then printed out.