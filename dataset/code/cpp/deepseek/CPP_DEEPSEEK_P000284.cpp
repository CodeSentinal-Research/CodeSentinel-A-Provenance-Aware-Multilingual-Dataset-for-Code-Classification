Sure, here is the C++ code for the edit distance problem.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i][j - 1],         
                                   min(dp[i - 1][j],       
                                      dp[i - 1][j - 1]));  
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Minimum cost of编辑: " << editDistance(s1, s2) << endl;
    return 0;
}

This code uses dynamic programming to find the minimum edit distance. The dp[i][j] represents the minimum number of operations needed to convert the first i characters of s1 into the first j characters of s2. The base case is when either of the strings is empty, so we have 0 operations for those. If s1 is empty, we need to insert all characters from s2, and if s2 is empty, we need to remove all characters from s1. If the characters at the current positions in both strings are the same, we ignore the current characters and move onto the next characters. If they are different, we need to perform an operation (insert, remove, or replace) to make them the same. We then use the previously computed values in the dp table to find the minimum number of operations.