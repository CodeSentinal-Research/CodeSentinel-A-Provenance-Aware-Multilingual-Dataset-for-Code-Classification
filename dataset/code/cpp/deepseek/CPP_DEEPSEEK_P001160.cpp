#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countDistinctSubsequences(string S, string T) {
    int m = S.length(), n = T.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for(int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for(int j = 1; j <= n; j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string S, T;
    cin >> S >> T;
    cout << countDistinctSubsequences(S, T) << endl;
    return 0;
}
This code uses a dynamic programming approach to solve the problem. The dp array stores the number of distinct subsequences of each prefix of string S that equals to each prefix of string T. The base cases are initially set to 0 and 1, representing the empty string and the single character string, respectively. Then, for each pair of characters in S and T, we update the dp array accordingly.