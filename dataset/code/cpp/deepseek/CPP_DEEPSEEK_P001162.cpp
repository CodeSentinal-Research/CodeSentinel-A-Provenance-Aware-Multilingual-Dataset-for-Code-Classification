#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;

    int n = s.length(), m = p.length();

    bool dp[n + 1][m + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = false;
            else if(j == 0)
                dp[i][j] = true;
            else if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        }
    }

    if(dp[n][m])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
This C++ solution uses dynamic programming to solve the Regular Expression Matching problem. The solution works by creating a 2D array (dp) where dp[i][j] is true if the first i characters of s match the first j characters of p, otherwise false. We then fill this array by examining p from left to right and s from right to left. If p is '*', we can ignore the character in p and check dp[i][j - 1] or dp[i - 1][j], which means we can ignore the current character in p and check the remaining part in s.