#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    int ans = INT_MIN;
    for(int i=0;i<n-1;i++) for(int j=0;j<n-1;j++) {
        int mn = INT_MAX, mx = INT_MIN;
        for(int x=i;x<n;x++) for(int y=j;y<n;y++) {
            if(x==i && y==j) continue;
            mn = min(mn, g[x][y]); mx = max(mx, g[x][y]);
        }
        ans = max(ans, max(0, vals[i][j]-mn)); // Simplified logic
    }
    cout << ans << endl;
    return 0;
}
