#include <iostream>
#include <string>
using namespace std;

bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    if (s1 == s2) return true;
    for (int i = 0; i < s1.length(); i++) {
        if ((s1[i] == s2[0] && isScramble(s1.substr(1), s2.substr(1))) return true;
        if (s1[i] == s2[0] && isScramble(s1.substr(i+1), s2.substr(1))) return true;
        if (s1[i] == s2[0] && isScramble(s1.substr(1), s2.substr(i+1))) return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (isScramble(s1, s2)) cout << "YES"; else cout << "NO";
    return 0;
}