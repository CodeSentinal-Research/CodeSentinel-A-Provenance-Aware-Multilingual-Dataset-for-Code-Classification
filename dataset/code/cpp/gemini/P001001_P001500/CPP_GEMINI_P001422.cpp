#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        std::unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        std::unordered_set<char> row3{'z','x','c','v','b','n','m'};

        std::vector<std::string> res;
        for (const auto& w : words) {
            bool r1 = true, r2 = true, r3 = true;
            for (char c : w) {
                char lower = std::tolower(c);
                if (!row1.count(lower)) r1 = false;
                if (!row2.count(lower)) r2 = false;
                if (!row3.count(lower)) r3 = false;
            }
            if (r1 || r2 || r3) res.push_back(w);
        }
        return res;
    }
};