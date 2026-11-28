#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    string res = "";
    for(int i=0;i<s.size();i++) {
        char c = s[i]; int cnt=1;
        while(i+1<s.size() && s[i+1]==c) { cnt++; i++; }
        res += c + to_string(cnt);
    }
    cout << (res.size()<s.size()?res:s) << endl;
    return 0;
}
