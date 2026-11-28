#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    for(int d=0;d<r+c-1;d++) {
        int r0 = max(0, d-c+1), c0 = min(d, c-1);
        for(int i=r0, j=c0; i<r && j>=0; i++, j--) cout << g[i][j] << " ";
    }
    cout << endl;
    return 0;
}
