#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // DP with map to store possible sums at each cell
    // dp[i][j] is a map of sum -> count
    vector<vector<map<long long, long long>>> dp(n, vector<map<long long, long long>>(m));
    
    dp[0][0][grid[0][0]] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            
            if (i > 0) {
                for (auto& p : dp[i-1][j]) {
                    dp[i][j][p.first + grid[i][j]] += p.second;
                }
            }
            if (j > 0) {
                for (auto& p : dp[i][j-1]) {
                    dp[i][j][p.first + grid[i][j]] += p.second;
                }
            }
        }
    }
    
    cout << dp[n-1][m-1][target] << endl;
    return 0;
}
