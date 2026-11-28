Here is the C++ code to solve the given problem:

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    if (dict.find(s) != dict.end())
        return true;
    for (int i = 1; i < s.size(); ++i) {
        string word = s.substr(0, i);
        string remain = s.substr(i);
        if (dict.find(word) != dict.end() && wordBreak(remain, dict)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    string s;
    cin >> s >> n;
    unordered_set<string> dict;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        dict.insert(word);
    }
    vector<string> res;
    wordBreak(s, dict);
    return 0;
}
This program reads a string and a number n. It then reads n strings, inserting them into a set (hash set). The main function then uses the wordBreak function to check if the input string can be split into words in the dictionary. If the word is found in the dictionary, the function is called recursively on the remaining part of the string. If the word is not found in the dictionary, the function returns false. The result is stored in a vector. The program then prints the vector, sorted lexicographically.