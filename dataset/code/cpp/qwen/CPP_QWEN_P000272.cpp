#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    string p = "";
    for(int i=0;i<s[0].size();i++) {
        char c = s[0][i];
        for(int j=1;j<n;j++) if(i>=s[j].size() || s[j][i]!=c) goto end;
        p += c;
    }
    end: cout << p << endl;
    return 0;
}
