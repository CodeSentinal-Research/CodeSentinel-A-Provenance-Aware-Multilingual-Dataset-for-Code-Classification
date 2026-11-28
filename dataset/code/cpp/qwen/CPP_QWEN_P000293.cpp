#include <bits/stdc++.h>
using namespace std;
string encode(vector<string>& v) { string r=""; for(string& s : v) r += to_string(s.size()) + "#" + s; return r; }
vector<string> decode(string s) { vector<string> r; int i=0; while(i<s.size()) { int j=s.find('#',i); int len=stoi(s.substr(i,j-i)); r.push_back(s.substr(j+1,len)); i=j+1+len; } return r; }
int main() {
    int n; cin >> n;
    vector<string> v(n); for(int i=0;i<n;i++) cin >> v[i];
    string e = encode(v);
    vector<string> d = decode(e);
    for(string& s : d) cout << s << " ";
    cout << endl;
    return 0;
}
