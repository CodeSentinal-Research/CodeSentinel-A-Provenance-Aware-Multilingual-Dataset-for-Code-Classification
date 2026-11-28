#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    vector<vector<int>> p(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) p[i][j]+=g[i][k]*g[j][k];
    bool ok = true;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(p[i][j] != (i==j?1:0)) ok=false;
    cout << (ok?"Yes":"No") << endl;
    return 0;
}
