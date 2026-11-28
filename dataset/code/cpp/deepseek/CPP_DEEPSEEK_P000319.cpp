#include <iostream>
using namespace std;

bool isOneEditDistance(string s, string t) {
    if (s.length() > t.length()) swap(s, t);

    int m = s.length(), n = t.length();
    for (int i = 0; i < n; i++) {
        if (m - i > 1 && s[i] != t[i]) {
            return false;
        }
        if (s[i] != t[i]) {
            if (m == n) return false;
            return s.substr(i+1) == t.substr(i);
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (isOneEditDistance(s, t)) cout << "Yes";
    else cout << "No";
    return 0;
}