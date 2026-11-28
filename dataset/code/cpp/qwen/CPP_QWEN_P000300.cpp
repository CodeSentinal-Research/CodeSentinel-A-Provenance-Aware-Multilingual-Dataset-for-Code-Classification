#include <bits/stdc++.h>
using namespace std;
void gen(string& d, int i, string s, vector<string>& res) {
    if(i==d.size()) { res.push_back(s); return; }
    string chars = "abc def ghi jkl mno pqrs tuv wxyz".substr((d[i]-'2')*4, 3+(d[i]=='7'||d[i]=='9'?1:0));
    // Simplified mapping
    string map[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string c = map[d[i]-'2'];
    for(char c : c) gen(d,i+1,s+c,res);
}
int main() {
    string d; cin >> d;
    vector<string> res;
    gen(d,0,"",res);
    for(string& s : res) cout << s << " ";
    cout << endl;
    return 0;
}
