#include <bits/stdc++.h>
using namespace std;
bool check(string& s, int l, int r) { while(l<r) if(s[l++]!=s[r--]) return false; return true; }
int main() {
    string s; cin >> s;
    int l=0, r=s.size()-1;
    while(l<r) {
        if(s[l]!=s[r]) { cout << (check(s,l+1,r)||check(s,l,r-1)?"Yes":"No") << endl; return 0; }
        l++; r--;
    }
    cout << "Yes" << endl;
    return 0;
}
