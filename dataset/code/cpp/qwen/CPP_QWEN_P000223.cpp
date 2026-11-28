#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int ans = 0, end = INT_MIN;
    for(auto& p : a) if(p.first >= end) { ans++; end = p.second; }
    cout << ans << endl;
    return 0;
}
