#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int ans=0, l=0;
    unordered_set<char> st;
    for(int r=0;r<s.size();r++) {
        while(st.count(s[r])) st.erase(s[l++]);
        st.insert(s[r]);
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}
