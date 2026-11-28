#include <iostream>
#include <unordered_map>
using namespace std;

bool areIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> m1, m2;
    for (int i = 0; i < s.size(); i++) {
        if (m1.find(s[i]) != m1.end()) {
            if (m1[s[i]] != t[i]) return false;
        } else {
            m1[s[i]] = t[i];
        }
        if (m2.find(t[i]) != m2.end()) {
            if (m2[t[i]] != s[i]) return false;
        } else {
            m2[t[i]] = s[i];
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (areIsomorphic(s, t)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}