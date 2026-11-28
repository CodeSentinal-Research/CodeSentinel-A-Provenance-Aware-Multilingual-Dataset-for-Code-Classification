Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> prefix(rows, vector<int>(cols));
    prefix[0][0] = matrix[0][0];
    for (int i = 1; i < rows; ++i)
        prefix[i][0] = prefix[i-1][0] + matrix[i][0];
    for (int j = 1; j < cols; ++j)
        prefix[0][j] = prefix[0][j-1] + matrix[0][j];

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j];
        }
    }

    int maxSum = INT_MIN;
    for (int left = 0; left < cols; ++left) {
        for (int right = left; right < cols; ++right) {
            int sum = 0;
            for (int i = 0; i < rows; ++i) {
                sum = prefix[i][right] - (left > 0 ? prefix[i][left-1] : 0);
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << solve(matrix) << '\n';

    return 0;
}

This code first computes the prefix sums of the input matrix, then finds the maximum sum in each rectangle (by iterating over all possible bottom-right corners of rectangles) and updates the maximum sum encountered so far.