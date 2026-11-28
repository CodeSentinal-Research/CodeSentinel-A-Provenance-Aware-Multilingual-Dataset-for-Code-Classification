#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> memo;

bool canWin(string s) {
    if (memo.find(s) != memo.end()) return memo[s];
    
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] == '+' && s[i+1] == '+') {
            string next = s.substr(0, i) + "--" + s.substr(i + 2);
            if (!canWin(next)) {
                memo[s] = true;
                return true;
            }
        }
    }
    
    memo[s] = false;
    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (canWin(s) ? "true" : "false") << endl;
    return 0;
}
