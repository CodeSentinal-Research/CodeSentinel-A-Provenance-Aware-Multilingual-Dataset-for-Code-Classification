#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> memo;

bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    string key = s1 + "#" + s2;
    if (memo.find(key) != memo.end()) return memo[key];
    
    int n = s1.length();
    bool flag = false;
    
    for (int i = 1; i < n; ++i) {
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
            (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
            flag = true;
            break;
        }
    }
    
    memo[key] = flag;
    return flag;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isScramble(s1, s2) ? "true" : "false") << endl;
    return 0;
}
