Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minChar(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for(int i=0; i<=m; i++) {
        dp[i][0] = 0;
    }

    for(int j=0; j<=n; j++) {
        dp[0][j] = 0;
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int lcs = dp[m][n];
    return (t.length() - lcs);
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minChar(s, t) << endl;
    return 0;
}

This code uses dynamic programming to solve the problem. The `minChar` function creates a 2D dynamic programming table `dp` where `dp[i][j]` represents the length of the longest common subsequence of the first `i` characters of `s` and the first `j` characters of `t`. 

The dynamic programming table is filled bottom-up. For each character in both strings, we check if the characters are the same. If they are, we increment the longest common subsequence length by 1. If they are not the same, we select the longest common subsequence of the previous characters in `s` and `t`. 

Finally, the minimum number of characters to append to `s` to make `t` a subsequence is the difference between the length of `t` and the length of the longest common subsequence of `s` and `t`.