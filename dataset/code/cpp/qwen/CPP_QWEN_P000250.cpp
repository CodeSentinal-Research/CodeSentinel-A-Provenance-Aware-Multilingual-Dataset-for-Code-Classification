#include <bits/stdc++.h>
using namespace std;
int det(vector<vector<int>>& m, int n) {
    if(n==1) return m[0][0];
    int d=0;
    for(int f=0;f<n;f++) {
        vector<vector<int>> sub(n-1, vector<int>(n-1));
        for(int i=1;i<n;i++) { int sj=0; for(int j=0;j<n;j++) if(j!=f) sub[i-1][sj++]=m[i][j]; }
        d += (f%2==0?1:-1) * m[0][f] * det(sub, n-1);
    }
    return d;
}
int main() {
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>m[i][j];
    cout << det(m, n) << endl;
    return 0;
}
