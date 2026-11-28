#include <iostream>
#include <unordered_map>
using namespace std;

bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    if(s1 == s2) return true;

    unordered_map<char, int> m;
    for(char c : s1) m[c]++;
    for(char c : s2) m[c]--;
    for(char c : s1) if (m[c] != 0) return false;

    for(int i = 0; i < s1.size(); i++) {
        if(isScramble(s1.substr(0, i), s2.substr(0, i)) &&
           isScramble(s1.substr(i), s2.substr(i))) return true;
        if(isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) &&
           isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isScramble(s1, s2) ? "true" : "false");
    return 0;
}