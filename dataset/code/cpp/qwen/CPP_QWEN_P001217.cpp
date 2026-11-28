#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    // isPal[i][j] = true if s[i..j] is palindrome
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) isPal[i][i] = true;
    for (int i = 0; i < n - 1; ++i) isPal[i][i+1] = (s[i] == s[i+1]);
    
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
        }
    }
    
    // dp[i] = min cuts for s[0..i]
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (isPal[0][i]) {
            dp[i] = 0;
        } else {
            for (int j = 1; j <= i; ++j) {
                if (isPal[j][i]) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
    }
    
    cout << dp[n-1] << endl;
    return 0;
}
