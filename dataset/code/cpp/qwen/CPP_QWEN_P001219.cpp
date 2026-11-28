#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void solve(const string& s, int start, const unordered_set<string>& dict, string current, vector<string>& result) {
    if (start == s.length()) {
        result.push_back(current.substr(1)); // Remove leading space
        return;
    }
    
    for (int end = start + 1; end <= s.length(); ++end) {
        string word = s.substr(start, end - start);
        if (dict.find(word) != dict.end()) {
            solve(s, end, dict, current + " " + word, result);
        }
    }
}

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
    
    vector<string> result;
    solve(s, 0, dict, "", result);
    
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    
    return 0;
}
