#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubsequence(const string& s, const string& word) {
    int i = 0, j = 0;
    while (i < s.length() && j < word.length()) {
        if (s[i] == word[j]) j++;
        i++;
    }
    return j == word.length();
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    string longest = "";
    while (n--) {
        string word;
        cin >> word;
        if (isSubsequence(s, word)) {
            if (word.length() > longest.length() || (word.length() == longest.length() && word < longest)) {
                longest = word;
            }
        }
    }
    
    cout << longest << endl;
    return 0;
}
