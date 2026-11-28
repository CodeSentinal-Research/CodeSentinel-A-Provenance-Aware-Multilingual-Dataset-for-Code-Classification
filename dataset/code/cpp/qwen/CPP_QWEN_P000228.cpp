#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, t; cin >> r >> c >> t;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int i=0, j=c-1;
    while(i<r && j>=0) {
        if(g[i][j]==t) { cout << "Found" << endl; return 0; }
        if(g[i][j]>t) j--; else i++;
    }
    cout << "Not Found" << endl;
    return 0;
}
