#include <iostream>
#include <vector>

using namespace std;

int countSubmatrices(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) dp[i + 1][j + 1] = 0;
            else dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + matrix[i][j];
        }
    }
    
    int count = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int p = i; p <= n; p++) {
                for(int q = j; q <= m; q++) {
                    if(dp[p][q] - dp[p - i][q] - dp[p][q - j] + dp[p - i][q - j] == i * j) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << countSubmatrices(matrix) << endl;
    
    return 0;
}