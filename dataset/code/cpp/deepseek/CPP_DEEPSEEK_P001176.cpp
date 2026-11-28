#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) {
                matrix[i][j] += max(matrix[i-1][j-1], matrix[i-1][j]);
            }
            matrix[i][j] += matrix[i-1][j];
        }
    }

    int maxSum = 0;
    for (int j = 0; j < N; ++j) {
        maxSum = max(maxSum, matrix[N-1][j]);
    }

    cout << maxSum << endl;

    return 0;
}