#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    unordered_map<int, int> cnt;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        if(j==0 || vals[i][j]!=vals[i][j-1]) cnt[vals[i][j]]++;
    }
    // Simplified: just count occurrences in each row
    for(int i=0;i<r;i++) {
        set<int> s(g[i].begin(), g[i].end());
        for(int x : s) cnt[x]++;
    }
    for(auto& p : cnt) if(p.second == r) cout << p.first << " ";
    cout << endl;
    return 0;
}
