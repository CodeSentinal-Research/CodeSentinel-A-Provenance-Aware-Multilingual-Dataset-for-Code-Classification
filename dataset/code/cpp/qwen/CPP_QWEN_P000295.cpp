#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int i=0, sign=1, res=0;
    while(i<s.size() && s[i]==' ') i++;
    if(i<s.size() && (s[i]=='+'||s[i]=='-')) { if(s[i]=='-') sign=-1; i++; }
    while(i<s.size() && isdigit(s[i])) { res = res*10+(s[i++]-'0'); if(res > INT_MAX/10) break; }
    cout << res*sign << endl;
    return 0;
}
