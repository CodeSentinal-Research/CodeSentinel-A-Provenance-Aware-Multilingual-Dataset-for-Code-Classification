#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return (a > b)? a: b;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '1') {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                result = max(result, dp[i][j]);
            }
        }
    }

    return result * result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maximalSquare(matrix) << endl;
    return 0;
}