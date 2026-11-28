#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool matches(const string& word, const string& pattern) {
    if (word.length() != pattern.length()) return false;
    unordered_map<char, char> w2p, p2w;
    
    for (int i = 0; i < word.length(); ++i) {
        char w = word[i], p = pattern[i];
        if (w2p.count(w) && w2p[w] != p) return false;
        if (p2w.count(p) && p2w[p] != w) return false;
        w2p[w] = p;
        p2w[p] = w;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    string pattern;
    cin >> pattern;
    
    for (const string& w : words) {
        if (matches(w, pattern)) cout << w << endl;
    }
    
    return 0;
}
