#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string text, string pattern) {
    if (text.length() < pattern.length()) {
        return vector<int>();
    }

    unordered_map<char, int> textCount, patternCount;
    for (int i = 0; i < pattern.length(); i++) {
        textCount[text[i]]++;
        patternCount[pattern[i]]++;
    }

    vector<int> indices;
    if (textCount == patternCount) {
        indices.push_back(0);
    }

    for (int i = pattern.length(); i < text.length(); i++) {
        textCount[text[i]]++;
        if (textCount[text[i]] == patternCount[text[i]]) {
            indices.push_back(i - pattern.length() + 1);
        }
    }

    return indices;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> indices = findAnagrams(text, pattern);

    cout << "Indices: ";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }

    return 0;
}