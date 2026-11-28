#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::unordered_map<std::string, int> count;
        std::istringstream iss(s1 + " " + s2);
        std::string w;
        while (iss >> w) count[w]++;

        std::vector<std::string> res;
        for (const auto& [word, cnt] : count) {
            if (cnt == 1) res.push_back(word);
        }
        return res;
    }
};