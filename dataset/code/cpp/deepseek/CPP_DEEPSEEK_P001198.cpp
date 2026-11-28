Here is the complete C++ code for the given problem. This program uses Dynamic Programming to solve the problem. It calculates the area for all possible submatrices (from top left to bottom right) and stores the maximum area found so far.

#include <iostream>
#include <vector>

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    int maxSize = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize * maxSize;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << countSquares(matrix);

    return 0;
}

This code first takes the number of rows and columns as input, then it takes a 2D matrix of integers as input. Then it calls the `countSquares` function which returns the total number of square submatrices consisting entirely of ones.