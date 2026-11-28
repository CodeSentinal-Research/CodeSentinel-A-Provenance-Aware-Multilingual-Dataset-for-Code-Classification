#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
    for(int i=0;i<n/2;i++) for(int j=i;j<n-1-i;j++) {
        int tmp = g[i][j];
        g[i][j] = g[n-1-j][i]; g[n-1-j][i] = g[n-1-i][n-1-j];
        g[n-1-i][n-1-j] = g[j][n-1-i]; g[j][n-1-i] = tmp;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout << g[i][j] << " ";
    cout << endl;
    return 0;
}
