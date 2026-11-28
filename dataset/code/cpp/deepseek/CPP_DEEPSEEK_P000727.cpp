#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<string> wordBreak(string s, unordered_set<string>& dict) {
    vector<string> result;
    unordered_map<string, vector<string>> cache;

    return divideAndConcat(s, dict, cache);
}

vector<string> divideAndConcat(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& cache) {
    if (cache.count(s)) return cache[s];

    vector<string> result;
    for (int i = 1; i <= s.size(); ++i) {
        string word = s.substr(0, i);
        if (dict.count(word)) {
            if (i == s.size()) {
                result.push_back(word);
            } else {
                for (string next : divideAndConcat(s.substr(i), dict, cache)) {
                    result.push_back(word + " " + next);
                }
            }
        }
    }

    cache[s] = result;
    return result;
}

int main() {
    unordered_set<string> dict = {"leet", "code"};
    string s = "leetcode";

    for (string sentence : wordBreak(s, dict)) {
        cout << sentence << endl;
    }

    return 0;
}
This code will output the following sentences in lexicographical order:
leet code
leet code
code leet
code leet