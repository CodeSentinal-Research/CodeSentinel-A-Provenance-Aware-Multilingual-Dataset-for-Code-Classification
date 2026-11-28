#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    s.erase(remove_if(s.begin(), s.end(), [](char c){ return string("aeiouAEIOU").find(c)!=string::npos; }), s.end());
    cout << s << endl;
    return 0;
}
