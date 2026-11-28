#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Compute 2D Prefix Sum
    vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    vector<vector<long long>> result(n, vector<long long>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int r1 = max(0, i - k);
            int c1 = max(0, j - k);
            int r2 = min(n - 1, i + k);
            int c2 = min(m - 1, j + k);
            
            // Convert to 1-based for prefix sum
            r1++; c1++; r2++; c2++;
            
            long long sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            result[i][j] = sum;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) cout << " ";
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}
