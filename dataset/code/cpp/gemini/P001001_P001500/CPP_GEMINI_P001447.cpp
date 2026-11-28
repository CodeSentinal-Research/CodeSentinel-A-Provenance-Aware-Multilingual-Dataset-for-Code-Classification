#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<std::string, std::string> parent;

    std::string find(const std::string& s) {
        if (!parent.count(s)) parent[s] = s;
        if (parent[s] != s) parent[s] = find(parent[s]);
        return parent[s];
    }

    void unite(const std::string& s1, const std::string& s2) {
        std::string r1 = find(s1), r2 = find(s2);
        if (r1 != r2) parent[r1] = r2;
    }
public:
    bool areSentencesSimilarTwo(std::vector<std::string>& sentence1, std::vector<std::string>& sentence2, std::vector<std::vector<std::string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        for (const auto& p : similarPairs) unite(p[0], p[1]);

        for (size_t i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] != sentence2[i] && find(sentence1[i]) != find(sentence2[i])) {
                return false;
            }
        }
        return true;
    }
};