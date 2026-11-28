#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    unordered_map<string, vector<string>> m;
    for(string& s : s) { string k=s; sort(k.begin(),k.end()); m[k].push_back(s); }
    for(auto& p : m) { for(string& s : p.second) cout << s << " "; cout << endl; }
    return 0;
}
