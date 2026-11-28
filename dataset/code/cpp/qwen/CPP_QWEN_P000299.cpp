#include <bits/stdc++.h>
using namespace std;
void gen(int n, int l, int r, string s, vector<string>& res) {
    if(s.size()==2*n) { res.push_back(s); return; }
    if(l<n) gen(n,l+1,r,s+"(",res);
    if(r<l) gen(n,l,r+1,s+")",res);
}
int main() {
    int n; cin >> n;
    vector<string> res;
    gen(n,0,0,"",res);
    for(string& s : res) cout << s << " ";
    cout << endl;
    return 0;
}
