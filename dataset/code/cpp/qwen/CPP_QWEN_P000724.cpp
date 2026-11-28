#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool hasUniqueChars(const string& s) {
    vector<bool> seen(26, false);
    for (char c : s) {
        if (seen[c - 'a']) return false;
        seen[c - 'a'] = true;
    }
    return true;
}

void maxLengthUniqueConcat(vector<string>& words, int index, string current, int& maxLen) {
    if (!hasUniqueChars(current)) return;
    
    maxLen = max(maxLen, (int)current.length());
    
    if (index == words.size()) return;
    
    // Skip
    maxLengthUniqueConcat(words, index + 1, current, maxLen);
    // Include
    maxLengthUniqueConcat(words, index + 1, current + words[index], maxLen);
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    int maxLen = 0;
    maxLengthUniqueConcat(words, 0, "", maxLen);
    cout << maxLen << endl;
    return 0;
}
