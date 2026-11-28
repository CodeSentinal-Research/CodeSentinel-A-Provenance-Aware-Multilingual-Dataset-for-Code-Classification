Here is the C++ code for the problem:

#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n < 2) return s;

    bool dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                start = i;
                maxLen = length;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}

In this code, we are using the concept of Dynamic Programming to find the longest palindromic substring. We initialize a 2D boolean array dp where dp[i][j] is true if the string from index i to j is a palindrome. Then, we fill this array in a way that the longest palindromic substring is always at the end of the string.