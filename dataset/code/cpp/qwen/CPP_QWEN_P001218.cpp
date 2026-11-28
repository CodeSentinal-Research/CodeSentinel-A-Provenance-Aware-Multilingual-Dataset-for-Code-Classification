#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    unordered_set<string> dict;
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        dict.insert(word);
    }
    
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    
    cout << (dp[n] ? "YES" : "NO") << endl;
    return 0;
}
