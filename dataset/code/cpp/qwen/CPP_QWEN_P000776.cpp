#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void wordPartition(string s, vector<string>& dict, string current, vector<string>& result) {
    if (s.empty()) {
        result.push_back(current.substr(1));
        return;
    }
    for (const string& w : dict) {
        if (s.substr(0, w.length()) == w) {
            wordPartition(s.substr(w.length()), dict, current + " " + w, result);
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
    wordPartition(s, dict, "", result);
    
    for (const string& part : result) {
        cout << part << endl;
    }
    return 0;
}
