#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countWays(string s, int start, int k, vector<int>& dp) {
    if (start == s.length()) return 1;
    if (s[start] == '0') return 0;
    if (dp[start] != -1) return dp[start];
    
    long long num = 0;
    int ways = 0;
    for (int i = start; i < s.length(); ++i) {
        num = num * 10 + (s[i] - '0');
        if (num > k) break;
        ways = (ways + countWays(s, i + 1, k, dp)) % 1000000007;
    }
    return dp[start] = ways;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> dp(s.length(), -1);
    cout << countWays(s, 0, k, dp) << endl;
    return 0;
}
