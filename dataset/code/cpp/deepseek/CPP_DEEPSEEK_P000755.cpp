Here is the C++ code that you need:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateAbbreviations(string word, int index, string current, vector<string>& res) {
    if (index == word.size()) {
        if (current != "") {
            res.push_back(current);
        }
        return;
    }

    generateAbbreviations(word, index + 1, current, res); 

    if (current == "") {
        current = word[index];
    } else {
        current += to_string(word.substr(index + 1).size());
    }

    generateAbbreviations(word, index + 1, current, res); 
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    vector<string> res;
    generateAbbreviations(word, 0, "", res);

    sort(res.begin(), res.end());

    for (string s : res) {
        cout << s << endl;
    }

    return 0;
}

This code uses recursion to generate all abbreviations. It starts by recursing on the next character. If the current abbreviation is empty, it abbreviates the next character. If the current abbreviation is not empty, it appends the next character's length to the current abbreviation. The process is repeated until all characters in the word have been processed. The abbreviations are then sorted and printed out in lexicographical order.