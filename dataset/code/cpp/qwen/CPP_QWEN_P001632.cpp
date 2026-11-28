#include <iostream>
#include <vector>
#include <algorithm>
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
    
    int maxSide = 0;
    for (int side = 1; side <= min(n, m); ++side) {
        bool found = false;
        for (int i = 0; i + side - 1 < n; ++i) {
            for (int j = 0; j + side - 1 < m; ++j) {
                if (getSum(i, j, i + side - 1, j + side - 1) <= k) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) maxSide = side;
        else break;
    }
    
    cout << maxSide << endl;
    return 0;
}
