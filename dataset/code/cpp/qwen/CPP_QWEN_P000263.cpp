#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    unordered_map<char, int> cnt;
    for(char c : s) cnt[c]++;
    for(int i=s.size()-1;i>=0;i--) if(cnt[s[i]]==1) { cout << s[i] << endl; return 0; }
    cout << -1 << endl;
    return 0;
}
