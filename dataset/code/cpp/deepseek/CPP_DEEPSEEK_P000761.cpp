#include <iostream>
using namespace std;

int countDistinctSubsequences(string s, string t) {
    int m = s.length();
    int n = t.length();

    int dp[n+1][m+1];

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[j-1] == t[i-1]) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    cout << "Number of distinct subsequences is: " << countDistinctSubsequences(s, t);
    return 0;
}