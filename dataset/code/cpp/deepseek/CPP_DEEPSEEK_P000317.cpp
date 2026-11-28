#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

void findPattern(string pattern, string words) {
    unordered_map<char, string> map;
    vector<string> wordsList;
    istringstream iss(words);
    string word;

    while (iss >> word) {
        wordsList.push_back(word);
    }

    for (int i = 0; i < wordsList.size(); i++) {
        if (map.find(pattern[i]) != map.end()) {
            if (map[pattern[i]] != wordsList[i]) {
                cout << "No";
                return;
            }
        } else {
            map[pattern[i]] = wordsList[i];
        }
    }

    cout << "Yes";
}

int main() {
    string pattern, words;

    cout << "Enter pattern: ";
    cin >> pattern;
    cout << "Enter words: ";
    cin.ignore();
    getline(cin, words);

    findPattern(pattern, words);

    return 0;
}
This C++ program reads a pattern and a string of words, then checks if the pattern matches the words. If the pattern matches the words, it prints "Yes", otherwise it prints "No".