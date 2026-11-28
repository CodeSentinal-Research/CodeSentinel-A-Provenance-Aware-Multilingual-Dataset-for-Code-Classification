#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    for(int i=0;i<n;i++) {
        int mn = *min_element(g[i].begin(), g[i].end());
        int j = find(g[i].begin(), g[i].end(), mn) - g[i].begin();
        bool mx = true;
        for(int k=0;k<n;k++) if(g[k][j] > vals[i][j]) { mx=false; break; }
        if(mx) { cout << vals[i][j] << endl; return 0; }
    }
    cout << "No Saddle Point" << endl;
    return 0;
}
