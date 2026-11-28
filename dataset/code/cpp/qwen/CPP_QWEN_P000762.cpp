#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p, int i, int j) {
    if (j == p.length()) return i == s.length();
    
    bool firstMatch = (i < s.length() && (p[j] == s[i] || p[j] == '?'));
    
    if (p[j] == '*') {
        return isMatch(s, p, i, j + 1) || (i < s.length() && isMatch(s, p, i + 1, j));
    } else {
        return firstMatch && isMatch(s, p, i + 1, j + 1);
    }
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p, 0, 0) ? "true" : "false") << endl;
    return 0;
}
