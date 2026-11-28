#include <iostream>
#include <string>
using namespace std;
string revStr(const string& s, int l, int r) {
    if(l >= r) return s;
    string res = s;
    swap(res[l], res[r]);
    return revStr(res, l + 1, r - 1);
}
int main() {
    string s; cin >> s;
    cout << revStr(s, 0, s.length() - 1) << endl;
    return 0;
}
