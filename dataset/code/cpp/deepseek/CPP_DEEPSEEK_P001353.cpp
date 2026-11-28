Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(string s, int k) {
    long long ans = 0;
    int n = s.size();
    s = '1' + s;
    vector<int> dp(n + 2, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (s[i] != '0') {
            dp[i] += dp[i - 1];
        }
        dp[i] %= k;
        if (s[i - 1] == '1' && s[i] == '0') {
            ans += dp[i - 1];
        }
        ans %= k;
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << solve(s, k);
    return 0;
}
This program uses dynamic programming to solve the problem. The state dp[i] represents the number of ways to split the string up to index i. If the last digit of the substring is not 0, dp[i] += dp[i - 1] to include the valid split. If the last digit is 0 and the previous digit is 1, the total valid split can be added to the answer.