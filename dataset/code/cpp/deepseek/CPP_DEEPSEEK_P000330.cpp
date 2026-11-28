#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addBoldTags(string &s, vector<string> &words) {
    for (auto &word : words) {
        size_t pos = 0;
        while ((pos = s.find(word, pos)) != string::npos) {
            s.replace(pos, word.length(), "<b>" + word + "</b>");
            pos += word.length();
        }
    }
}

int main() {
    string s;
    vector<string> words;

    addBoldTags(s, words);

    cout << s << endl;

    return 0;
}
In this code, we use the `replace` function from the `<algorithm>` library to replace all occurrences of a word in the string with `<b></b>` tags. The `find` function is used to find the position of the word in the string, and the `replace` function is used to add the bold tags.