#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t; cin >> s >> t;
    unordered_map<char, int> cnt;
    for(char c : t) cnt[c]++;
    int req = t.size(), l=0, ans=INT_MAX, st=0;
    for(int r=0;r<s.size();r++) {
        if(cnt[s[r]]-->0) req--;
        while(req==0) {
            if(r-l+1<ans) { ans=r-l+1; st=l; }
            if(++cnt[s[l++]]>0) req++;
        }
    }
    cout << (ans==INT_MAX?"":s.substr(st,ans)) << endl;
    return 0;
}
