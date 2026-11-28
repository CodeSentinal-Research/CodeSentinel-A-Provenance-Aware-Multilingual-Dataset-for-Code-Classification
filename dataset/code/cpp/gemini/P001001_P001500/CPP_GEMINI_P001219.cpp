#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
    std::unordered_map<std::string, std::vector<std::string>> memo;
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        std::vector<std::string> res;
        for (const auto& w : wordDict) {
            if (s.rfind(w, 0) == 0) {
                auto sub = wordBreak(s.substr(w.length()), wordDict);
                for (const auto& sentence : sub) {
                    res.push_back(w + (sentence.empty() ? "" : " ") + sentence);
                }
            }
        }
        return memo[s] = res;
    }
};