#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s = "1";
    for(int i=1;i<n;i++) {
        string t = "";
        for(int j=0;j<s.size();j++) {
            char c = s[j]; int cnt=1;
            while(j+1<s.size() && s[j+1]==c) { cnt++; j++; }
            t += to_string(cnt) + c;
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}
