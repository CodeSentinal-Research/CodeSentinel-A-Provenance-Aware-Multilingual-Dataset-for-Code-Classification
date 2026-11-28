#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, k; cin >> r >> c >> k;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    for(int i=0;i<r;i++) rotate(g[i].begin(), g[i].begin()+(c-k%c)%c, g[i].end());
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout << g[i][j] << " ";
    cout << endl;
    return 0;
}
