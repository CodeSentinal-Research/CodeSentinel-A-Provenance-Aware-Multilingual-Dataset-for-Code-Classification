#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
            }
            if (j < n - 1) {
                matrix[i][j] += min(matrix[i - 1][j + 1], matrix[i - 1][j]);
            }
        }
    }

    int minPath = INT_MAX;
    for (int j = 0; j < n; ++j) {
        minPath = min(minPath, matrix[n - 1][j]);
    }

    return minPath;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << minFallingPathSum(matrix) << endl;

    return 0;
}