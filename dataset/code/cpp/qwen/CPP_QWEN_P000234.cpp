#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    vector<bool> row(r, false), col(c, false);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(g[i][j]) { row[i]=true; col[j]=true; }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(row[i]||col[j]) g[i][j]=1;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout << g[i][j] << " ";
    cout << endl;
    return 0;
}
