Here is a simple C++ code for the problem:

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

    int maxRow = 0;
    int maxCount = 0;

    for(int i = 0; i < rows; i++) {
        int count = 0;
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }

    cout << maxRow << endl;

    return 0;
}

This code reads the number of rows and columns from the standard input, then reads the matrix from the standard input. It then iterates through the rows and counts the number of 1s in each row. If the count of a row is more than the current maximum count, it updates the maximum count and the row index. Finally, it outputs the index of the row with the maximum count of 1s.