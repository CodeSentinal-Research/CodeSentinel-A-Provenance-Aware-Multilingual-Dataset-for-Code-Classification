#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    long long k;
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
    
    auto getSum = [&](int r1, int c1, int r2, int c2) -> long long {
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    };
    
    long long maxSum = LLONG_MIN;
    for (int r1 = 0; r1 < n; ++r1) {
        for (int c1 = 0; c1 < m; ++c1) {
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c2 = c1; c2 < m; ++c2) {
                    long long sum = getSum(r1, c1, r2, c2);
                    if (sum <= k) {
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }
    }
    
    cout << maxSum << endl;
    return 0;
}
