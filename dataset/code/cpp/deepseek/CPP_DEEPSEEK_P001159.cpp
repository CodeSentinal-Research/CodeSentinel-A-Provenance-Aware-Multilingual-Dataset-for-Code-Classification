Here is the C++ code for the problem.

#include <iostream>
using namespace std;

int solve(string str) {
    int n = str.length();
    int* dp = new int[n + 1];
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        if (str[i - 1] > '0') {
            dp[i] += dp[i - 1];
        }
        int num = (str[i - 2] - '0') + 10 * (str[i - 1] - '0');
        if (num <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    int res = dp[n];
    delete[] dp;
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << solve(str);
    return 0;
}

The code works by creating an array `dp` where `dp[i]` represents the number of ways to decode the string up to `i` characters. The base cases are `dp[0] = 1` and `dp[1] = 0`, as the string can't be empty or consist of just one character.

For each character from the second to the last, we check if the current number can be a single digit number, i.e., from '1' to '9'. If it can, we add the number of ways to decode the string up to `i - 1` characters to the current number of ways.

If the current number can be a two-digit number (i.e., from '10' to '26'), we add the number of ways to decode the string up to `i - 2` characters to the current number of ways.

At the end of the program, we return `dp[n]` which is the total number of decodings.