#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    int ans = 0;
    for(int i=0;i<n;i++) ans += lower_bound(g[i].begin(), g[i].end(), 1) - g[i].begin();
    cout << ans << endl;
    return 0;
}
