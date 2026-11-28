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
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                for(int k = 0; k < cols; k++) {
                    matrix[i][k] = 0;
                }

                for(int k = 0; k < rows; k++) {
                    matrix[k][j] = 0;
                }
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
This code first reads the number of rows and columns from the input. Then, it reads the matrix elements. After that, it sets all the elements at the corresponding row and column to zero if the element is zero. Finally, it prints the modified matrix.