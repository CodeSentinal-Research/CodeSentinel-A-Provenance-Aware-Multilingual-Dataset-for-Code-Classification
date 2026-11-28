Here's the C++ code for the problem:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    unordered_set<char> chars;
    for (string s : strs) {
        for (char c : s) {
            chars.insert(c);
        }
    }
    int maxLen = 0;
    for (string s : strs) {
        unordered_set<char> tmpChars;
        int len = 0;
        for (char c : s) {
            if (tmpChars.find(c) == tmpChars.end()) {
                tmpChars.insert(c);
                len++;
            }
        }
        maxLen = max(maxLen, len);
    }
    cout << maxLen << endl;
    return 0;
}

This code first reads the number of strings `n` and then the strings themselves. It then finds all unique characters in all strings and stores them in a set. Afterwards, it iterates over all strings and calculates the maximum length of a substring with no repeated characters. Finally, it prints the maximum length.