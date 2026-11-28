#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(string a, string b) {
    int m = a.size();
    int n = b.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;
    
    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < m; i++)
        sum1 += int(a[i]);
    for(int i = 0; i < n; i++)
        sum2 += int(b[i]);
        
    return abs(sum1 - sum2);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}