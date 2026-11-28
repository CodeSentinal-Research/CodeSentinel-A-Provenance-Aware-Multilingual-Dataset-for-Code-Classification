#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int ans=0, idx=0;
    for(int i=0;i<r;i++) {
        int c1 = lower_bound(g[i].begin(), g[i].end(), 1) - g[i].begin();
        if(c-c1 > ans) { ans = c-c1; idx = i; }
    }
    cout << idx << endl;
    return 0;
}
