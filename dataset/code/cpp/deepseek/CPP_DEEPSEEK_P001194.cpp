#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& a, int k) {
    int n = a.size();
    vector<int> dp(n + 1, 0), pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = max(pre[i], a[i]);
        for (int j = i; j > max(i - k, 0); --j) {
            dp[j] = max(dp[j], pre[j] - a[i] + dp[i + 1]);
        }
    }
    return dp[0];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a, k) << endl;
    return 0;
}