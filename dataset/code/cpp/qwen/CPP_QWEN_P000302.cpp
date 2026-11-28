#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> dict(m);
    for (int i = 0; i < m; i++) cin >> dict[i];
    
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (const string& word : dict) {
            if (i >= word.size() && dp[i - word.size()] && s.substr(i - word.size(), word.size()) == word) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << (dp[s.size()] ? "Yes" : "No") << endl;
    return 0;
}
