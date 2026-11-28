#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) cin >> piles[i];
    
    int total = accumulate(piles.begin(), piles.end(), 0);
    
    // dp[i][j] = max stones first player can collect from piles[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            int left = piles[i] + min(dp[i+2][j], dp[i+1][j-1]); // if i+2 > j, dp is 0
            int right = piles[j] + min(dp[i+1][j-1], dp[i][j-2]); // if i > j-2, dp is 0
            
            // Handle boundary conditions for min
            int takeLeft = piles[i];
            if (i + 1 <= j) takeLeft += min((i+2 <= j ? dp[i+2][j] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));
            
            int takeRight = piles[j];
            if (i <= j - 1) takeRight += min((i+1 <= j-1 ? dp[i+1][j-1] : 0), (i <= j-2 ? dp[i][j-2] : 0));
            
            dp[i][j] = max(takeLeft, takeRight);
        }
    }
    
    cout << (dp[0][n-1] * 2 >= total ? "YES" : "NO") << endl;
    return 0;
}
