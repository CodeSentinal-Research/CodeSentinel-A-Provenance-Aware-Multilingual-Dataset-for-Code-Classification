Here is the C++ code for your problem:

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int len1 = s1.length();
    int len2 = s2.length();

    int result = 0;
    int dp[len1 + 1][len2 + 1];

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    cout << result << endl;

    return 0;
}

This code uses dynamic programming to solve the problem. It defines a 2D array `dp` where `dp[i][j]` is the length of the longest common substring of `s1[0..i-1]` and `s2[0..j-1]`.

It then fills this table. If the characters at the current indices of both strings are the same, it increases the length of the common substring by 1. If not, it sets the current cell to 0 because we found no longer common characters.

The longest common substring is updated every time if a longer common substring is found.

The result is the maximum value in the `dp` table.