#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool areSentencesSimilar(std::vector<std::string>& sentence1, std::vector<std::string>& sentence2, std::vector<std::vector<std::string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        std::unordered_set<std::string> sim;
        for (const auto& p : similarPairs) {
            sim.insert(p[0] + "#" + p[1]);
            sim.insert(p[1] + "#" + p[0]);
        }

        for (size_t i = 0; i < sentence1.size(); i++) {
            const auto& w1 = sentence1[i];
            const auto& w2 = sentence2[i];
            if (w1 != w2 && !sim.count(w1 + "#" + w2)) return false;
        }
        return true;
    }
};