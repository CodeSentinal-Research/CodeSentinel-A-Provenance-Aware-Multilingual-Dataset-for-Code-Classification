#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    vector<string> pal(n+1);

    for (int i = 0; i <= n; i++) {
        pal[i] = string(1, s[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = i-1;
        for (int j = 1; j <= i; j++) {
            if (isPalindrome(pal, j, i)) {
                dp[i] = min(dp[i], dp[i-j]+1);
            }
        }
    }

    return dp[n];
}

bool isPalindrome(vector<string>& pal, int start, int end) {
    int len = end - start + 1;
    for (int i = 0; i < len/2; i++) {
        if (pal[start+i] != pal[end-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    return 0;
}