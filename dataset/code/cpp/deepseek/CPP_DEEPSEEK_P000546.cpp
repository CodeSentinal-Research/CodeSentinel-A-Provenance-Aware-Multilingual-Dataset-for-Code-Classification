Here is the C++ solution for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canReach(string s, int minJump, int maxJump, int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') continue;
        int start = max(0, i - maxJump);
        int end = min(i - minJump, i);
        for (int j = start; j <= end; j++) {
            if (dp[j] == 1) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n - 1] == 1;
}

int main() {
    string s;
    int minJump, maxJump, n;
    cin >> s >> minJump >> maxJump;
    n = s.length();
    cout << (canReach(s, minJump, maxJump, n) ? "true" : "false");
    return 0;
}
This code uses dynamic programming to solve the problem. The idea is to maintain an array dp where dp[i] is true if it is possible to reach the last index from index i, and false otherwise. We fill dp in a bottom-up manner. For each index i, if s[i] is '0', we skip this index and its jumps. Otherwise, we check all valid jumps from i and update dp[i] if dp[j] is true. At the end, dp[n - 1] is the answer.