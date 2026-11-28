#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    int ans = INT_MIN;
    for(int i=0;i<=r-3;i++) for(int j=0;j<=c-3;j++) {
        int sum = 0;
        for(int x=0;x<3;x++) for(int y=0;y<3;y++) sum += g[i+x][j+y];
        sum -= g[i+1][j] + g[i+1][j+2];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
