#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void wordBreakHelper(string s, vector<string>& dict, string current, vector<string>& result) {
    if (s.empty()) {
        result.push_back(current.substr(1)); // remove leading space
        return;
    }
    
    for (const string& word : dict) {
        if (s.substr(0, word.length()) == word) {
            wordBreakHelper(s.substr(word.length()), dict, current + " " + word, result);
        }
    }
}

int main() {
    string s;
    int m;
    cin >> s >> m;
    vector<string> dict(m);
    for (int i = 0; i < m; ++i) cin >> dict[i];
    
    vector<string> result;
    wordBreakHelper(s, dict, "", result);
    
    for (const string& sentence : result) {
        cout << sentence << endl;
    }
    return 0;
}
