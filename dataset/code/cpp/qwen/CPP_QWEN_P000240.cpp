#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int sum = 0;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(i==0||i==r-1||j==0||j==c-1) sum+=g[i][j];
    cout << sum << endl;
    return 0;
}
