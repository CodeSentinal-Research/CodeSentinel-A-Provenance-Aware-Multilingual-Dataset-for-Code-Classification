#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict, "");
    }

private:
    vector<string> wordBreak(string s, unordered_set<string>& dict, string curr) {
        if (s.empty()) {
            return {curr};
        }
        vector<string> res;
        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.find(word) != dict.end()) {
                string rem = s.substr(i);
                for (auto &str : wordBreak(rem, dict, curr + word + " ")) {
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};