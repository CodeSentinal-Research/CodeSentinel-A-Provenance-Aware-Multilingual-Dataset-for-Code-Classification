#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; int k; cin >> s >> k;
    int ans=0, l=0, mx=0;
    unordered_map<char, int> cnt;
    for(int r=0;r<s.size();r++) {
        mx = max(mx, ++cnt[s[r]]);
        while(r-l+1-mx > k) cnt[s[l++]]--;
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}
