#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int m = s1.length();
    int n = s2.length();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[m][n];
    
    return 0;
}

This C++ code uses a 2D dynamic programming approach to find the length of the longest common subsequence. It first initializes a 2D vector `dp` with the size of the two input strings. Then, it populates `dp` in a bottom-up manner. The length of the longest common subsequence is stored at `dp[m][n]`, where `m` and `n` are the lengths of the two input strings.