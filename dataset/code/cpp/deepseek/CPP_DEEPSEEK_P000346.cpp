#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestWord(string s, vector<string> words) {
    string longestWord = "";
    for (string word : words) {
        if (word.size() > longestWord.size()) {
            bool isSubsequence = true;
            for (int i = 0, j = 0; i < word.size() && j < longestWord.size(); i++) {
                if (word[i] == longestWord[j]) {
                    j++;
                }
            }
            if (j == longestWord.size()) {
                longestWord = word;
            }
        }
    }
    return longestWord.size();
}

int main() {
    int s_length;
    cin >> s_length;
    string s;
    cin.ignore();
    getline(cin, s);
    vector<string> words;
    string word;
    while (getline(cin, word)) {
        words.push_back(word);
    }
    int longestWordSize = findLongestWord(s, words);
    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() == longestWordSize) {
            cout << words[i] << endl;
        }
    }
    return 0;
}