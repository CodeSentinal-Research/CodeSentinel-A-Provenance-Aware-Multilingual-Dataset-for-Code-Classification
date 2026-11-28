#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, p; cin >> s >> p;
    vector<int> cnt(26,0), win(26,0);
    for(char c : p) cnt[c-'a']++;
    int req = p.size(), l=0;
    for(int r=0;r<s.size();r++) {
        if(--win[s[r]-'a'] >= 0) req--;
        if(r-l+1==p.size()) {
            if(req==0) { cout << "Yes" << endl; return 0; }
            if(++win[s[l++]-'a'] > 0) req++;
        }
    }
    cout << "No" << endl;
    return 0;
}
