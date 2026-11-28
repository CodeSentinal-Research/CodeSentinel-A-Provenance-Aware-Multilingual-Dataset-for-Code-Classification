#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), dp(n, 0);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int i=0;i<n;i++) {
        dp[i] = a[i];
        for(int j=0;j<i;j++) if(a[j]<a[i]) dp[i] = max(dp[i], dp[j]+a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
