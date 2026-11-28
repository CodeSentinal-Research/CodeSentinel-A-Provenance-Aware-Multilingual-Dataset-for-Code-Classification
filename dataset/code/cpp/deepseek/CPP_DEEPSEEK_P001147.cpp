Here is the code for the given problem in C++:

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    int maxLen = 0;
    int endIndex = -1;

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << maxLen << endl;
    if (maxLen > 0) {
        cout << s1.substr(endIndex - maxLen, maxLen) << endl;
    }

    return 0;
}

This program uses a dynamic programming approach to solve the longest common substring problem. It creates a 2D vector `dp` where `dp[i][j]` represents the length of the longest common substring ending at `s1[i]` and `s2[j]`. It then fills up the table in a bottom-up manner, starting from the smallest possible substrings and working up to the entire string. The length of the longest common substring is kept track of in the variable `maxLen` and the end index of this longest common substring is kept track of in the variable `endIndex`.