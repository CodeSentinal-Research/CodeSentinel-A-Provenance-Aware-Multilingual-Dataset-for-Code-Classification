Here is the C++ code that fulfills the problem:

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    string pattern, sentence;
    unordered_map<char, string> m;

    getline(cin, pattern);
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;

    int i = 0;

    while (ss >> word) {
        if (m.count(word[0])) {
            if (m[word[0]] != pattern.substr(i, word.size())) {
                cout << "NO";
                return 0;
            }
        } else {
            m[word[0]] = pattern.substr(i, word.size());
        }
        i += word.size();
    }

    if (i != pattern.size()) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}
In this code, we first read the pattern and sentence. Then we split the sentence into words. We use an unordered map to store the pattern characters and their corresponding words. We iterate over the words in the sentence. If the first word of the current word matches the pattern character, we check if the rest of the word matches the corresponding pattern substring. If it does not, we print "NO" and exit the program. If we finish iterating over the words in the sentence and the pattern substring does not match, we print "NO" again. If all the checks pass, we print "YES".