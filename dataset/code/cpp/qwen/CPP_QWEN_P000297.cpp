#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    unordered_map<char, int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int res = 0;
    for(int i=0;i<s.size();i++) res += (i+1<s.size() && m[s[i]]<m[s[i+1]] ? -m[s[i]] : m[s[i]]);
    cout << res << endl;
    return 0;
}
