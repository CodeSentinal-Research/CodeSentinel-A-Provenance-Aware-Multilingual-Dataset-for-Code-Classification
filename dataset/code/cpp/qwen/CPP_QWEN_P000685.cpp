#include <iostream>
#include <string>
using namespace std;
bool isPal(const string& s, int l, int r) {
    if(l >= r) return true;
    if(s[l] != s[r]) return false;
    return isPal(s, l + 1, r - 1);
}
int main() {
    string s; cin >> s;
    cout << (isPal(s, 0, s.length() - 1) ? "true" : "false") << endl;
    return 0;
}
