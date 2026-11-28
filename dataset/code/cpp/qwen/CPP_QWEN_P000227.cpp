#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int ans = INT_MIN;
    for(int l=0;l<c;l++) {
        vector<int> t(r, 0);
        for(int r2=l;r2<c;r2++) {
            for(int i=0;i<r;i++) t[i]+=g[i][r2];
            int mx=0, cur=0;
            for(int x : t) { cur+=x; mx=max(mx,cur); if(cur<0) cur=0; }
            ans = max(ans, mx);
        }
    }
    cout << ans << endl;
    return 0;
}
