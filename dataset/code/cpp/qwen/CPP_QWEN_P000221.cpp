#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    sort(p.begin(), p.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int ans = 0, end = INT_MIN;
    for(auto& p : p) if(p.first > end) { ans++; end = p.second; }
    cout << ans << endl;
    return 0;
}
