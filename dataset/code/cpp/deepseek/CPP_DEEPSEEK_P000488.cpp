#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> heights(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') {
                if (i == 0) heights[i][j] = 1;
                else heights[i][j] = heights[i-1][j] + 1;
           
                int currArea = heights[i][j];
                for (int k = j; k < cols && matrix[i][k] == '1'; ++k) {
                    currArea = min(currArea, heights[i][k]);
                    maxArea = max(maxArea, currArea * (k - j + 1));
                }
            }
        }
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}