#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c)), b(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>a[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>b[i][j];
    cout << (a==b?"Identical":"Not Identical") << endl;
    return 0;
}
