#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsequences(string s, string current, vector<string>& result) {
    if (s.empty()) {
        if (!current.empty()) result.push_back(current);
        return;
    }
    // Exclude first char
    generateSubsequences(s.substr(1), current, result);
    // Include first char
    generateSubsequences(s.substr(1), current + s[0], result);
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    generateSubsequences(s, "", result);
    sort(result.begin(), result.end());
    for (const string& sub : result) {
        cout << sub << endl;
    }
    return 0;
}
