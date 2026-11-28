#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(const string& s, const vector<string>& dict, int idx, string current, vector<string>& res) {
    if (idx == s.size()) {
        res.push_back(current.substr(0, current.size() - 1));
        return;
    }
    for (const string& word : dict) {
        if (s.substr(idx, word.size()) == word) {
            solve(s, dict, idx + word.size(), current + word + " ", res);
        }
    }
}

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<string> dict(m);
    for (int i = 0; i < m; i++) cin >> dict[i];
    vector<string> res;
    solve(s, dict, 0, "", res);
    for (const string& sentence : res) cout << sentence << endl;
    return 0;
}
