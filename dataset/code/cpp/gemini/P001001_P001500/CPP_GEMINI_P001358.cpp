#include <vector>
#include <string>

class Solution {
    void backtrack(const std::string& word, int idx, std::string cur, int count, std::vector<std::string>& res) {
        if (idx == (int)word.length()) {
            res.push_back(cur + (count > 0 ? std::to_string(count) : ""));
            return;
        }
        backtrack(word, idx + 1, cur, count + 1, res);
        backtrack(word, idx + 1, cur + (count > 0 ? std::to_string(count) : "") + word[idx], 0, res);
    }
public:
    std::vector<std::string> generateAbbreviations(std::string word) {
        std::vector<std::string> res;
        backtrack(word, 0, "", 0, res);
        return res;
    }
};