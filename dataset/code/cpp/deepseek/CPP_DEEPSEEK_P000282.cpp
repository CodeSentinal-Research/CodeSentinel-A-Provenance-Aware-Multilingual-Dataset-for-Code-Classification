#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubstring(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    int maxLen = 0;
    int endingIndex = -1;
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endingIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    if (maxLen == 0) {
        return "";
    } else {
        return s1.substr(endingIndex - maxLen, maxLen);
    }
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    string result = longestCommonSubstring(s1, s2);

    cout << "Longest common substring: " << result << endl;

    return 0;
}