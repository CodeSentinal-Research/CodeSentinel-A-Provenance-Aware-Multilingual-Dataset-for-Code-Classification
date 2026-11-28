#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    int c = 0;
    for(int i=1;i<n;i++) if(g[c][i]==0) c = i;
    for(int i=0;i<n;i++) if(i!=c && (g[c][i]==1 || g[i][c]==0)) { cout << -1 << endl; return 0; }
    cout << c << endl;
    return 0;
}
