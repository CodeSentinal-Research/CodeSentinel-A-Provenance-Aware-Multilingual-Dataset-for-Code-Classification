#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    string pattern, s;
    cin >> pattern;
    getline(cin, s);
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word) words.push_back(word);
    if (pattern.size() != words.size()) {
        cout << "No" << endl;
        return 0;
    }
    unordered_map<char, string> map_p;
    unordered_map<string, char> map_w;
    for (int i = 0; i < pattern.size(); i++) {
        if (map_p.count(pattern[i]) && map_p[pattern[i]] != words[i]) { cout << "No" << endl; return 0; }
        if (map_w.count(words[i]) && map_w[words[i]] != pattern[i]) { cout << "No" << endl; return 0; }
        map_p[pattern[i]] = words[i];
        map_w[words[i]] = pattern[i];
    }
    cout << "Yes" << endl;
    return 0;
}
