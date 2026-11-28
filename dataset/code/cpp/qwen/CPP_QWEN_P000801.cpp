#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    cin >> K;

    // Compute 2D Prefix Sum
    vector<vector<long long>> prefix(N + 1, vector<long long>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    vector<vector<int>> ans(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int r1 = max(0, i - K);
            int c1 = max(0, j - K);
            int r2 = min(N - 1, i + K);
            int c2 = min(M - 1, j + K);
            
            // Convert to 1-based for prefix sum query
            r1++; c1++; r2++; c2++;
            
            long long sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            ans[i][j] = (int)sum;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j > 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
