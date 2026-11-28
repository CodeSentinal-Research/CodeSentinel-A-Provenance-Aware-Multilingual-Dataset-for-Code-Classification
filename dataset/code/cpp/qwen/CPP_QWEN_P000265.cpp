#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    string res = "";
    unordered_set<char> seen;
    for(char c : s) if(seen.insert(c).second) res += c;
    cout << res << endl;
    return 0;
}
