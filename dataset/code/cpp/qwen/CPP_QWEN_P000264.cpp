#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    unordered_map<char, int> cnt;
    for(char c : s) cnt[c]++;
    for(auto& p : cnt) cout << p.first << ": " << p.second << " ";
    cout << endl;
    return 0;
}
