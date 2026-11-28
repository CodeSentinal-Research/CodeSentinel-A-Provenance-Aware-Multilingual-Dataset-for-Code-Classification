Here is the C++ code:

#include <iostream>
#include <vector>

using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}

This program uses a 2D dynamic programming approach to solve the problem. The `dp` table is initialized with zeroes. Then, for each character in both strings, it updates the dp table accordingly. The final value of the dp table represents the length of the longest common subsequence.