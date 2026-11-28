#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, string> a, pair<string, string> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> words(n);
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        string pattern;
        cin >> pattern;
        words[i] = make_pair(word, pattern);
    }
    string pattern;
    cin >> pattern;
    sort(words.begin(), words.end(), compare);
    for (int i = 0; i < n; i++) {
        if (words[i].second == pattern) {
            cout << words[i].first << endl;
        }
    }
    return 0;
}