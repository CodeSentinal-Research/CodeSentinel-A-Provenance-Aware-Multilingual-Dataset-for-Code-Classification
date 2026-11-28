#include <iostream>
#include <string>
#include <map>
using namespace std;

map<pair<string, string>, bool> memo;

bool isScramble(const string& s1, const string& s2) {
    if (s1 == s2) return true;
    if (s1.length() != s2.length()) return false;
    
    // Check character counts
    int count[26] = {0};
    for (char c : s1) count[c-'a']++;
    for (char c : s2) count[c-'a']--;
    for (int i = 0; i < 26; ++i) if (count[i] != 0) return false;
    
    auto key = make_pair(s1, s2);
    if (memo.find(key) != memo.end()) return memo[key];
    
    int n = s1.length();
    for (int i = 1; i < n; ++i) {
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
            (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
            return memo[key] = true;
        }
    }
    
    return memo[key] = false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isScramble(s1, s2) ? "YES" : "NO") << endl;
    return 0;
}
