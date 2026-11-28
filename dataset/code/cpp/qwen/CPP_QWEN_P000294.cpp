#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; int r; cin >> s >> r;
    vector<string> rows(r, "");
    int i=0, d=1, row=0;
    while(i<s.size()) { rows[row] += s[i++]; if(row==0) d=1; else if(row==r-1) d=-1; row+=d; }
    string res = ""; for(string& r : rows) res += r;
    cout << res << endl;
    return 0;
}
