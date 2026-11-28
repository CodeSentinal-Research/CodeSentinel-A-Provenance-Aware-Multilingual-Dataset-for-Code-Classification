#include <iostream>
#include <string>
using namespace std;

bool isMatchRegex(string s, string p, int i, int j) {
    if (j == p.length()) return i == s.length();
    
    bool firstMatch = (i < s.length() && (p[j] == s[i] || p[j] == '.'));
    
    if (j + 1 < p.length() && p[j+1] == '*') {
        return isMatchRegex(s, p, i, j + 2) || (firstMatch && isMatchRegex(s, p, i + 1, j));
    } else {
        return firstMatch && isMatchRegex(s, p, i + 1, j + 1);
    }
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatchRegex(s, p, 0, 0) ? "true" : "false") << endl;
    return 0;
}
