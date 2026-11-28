#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int, int> cnt, first, last;
    int deg = 0;
    for(int i=0;i<n;i++) {
        cnt[a[i]]++;
        if(!first.count(a[i])) first[a[i]] = i;
        last[a[i]] = i;
        deg = max(deg, cnt[a[i]]);
    }
    int ans = n;
    for(auto& p : cnt) if(p.second == deg) ans = min(ans, last[p.first]-first[p.first]+1);
    cout << ans << endl;
    return 0;
}
