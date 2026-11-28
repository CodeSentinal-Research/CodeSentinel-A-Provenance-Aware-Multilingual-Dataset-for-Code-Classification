#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int maxWords(string brokenLetters, string text) {
    set<char> brokenChars(brokenLetters.begin(), brokenLetters.end());
    string word = "";
    int count = 0;

    for (char c : text) {
        if (brokenChars.find(c) == brokenChars.end()) {
            word += c;
        } else {
            count += word.size();
            word = "";
        }
    }

    if (!word.empty()) {
        count += word.size();
    }

    return count;
}

int main() {
    string brokenLetters, text;

    cout << "Enter the broken letters: ";
    cin >> brokenLetters;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Maximum words you can type: " << maxWords(brokenLetters, text) << endl;

    return 0;
}