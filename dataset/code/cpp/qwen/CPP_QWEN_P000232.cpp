#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int l=1, r2=1e9;
    while(l<r2) {
        int mid=(l+r2)/2, cnt=0;
        for(int i=0;i<r;i++) cnt += upper_bound(g[i].begin(), g[i].end(), mid) - g[i].begin();
        if(cnt < (r*c+1)/2) l=mid+1; else r2=mid;
    }
    cout << l << endl;
    return 0;
}
