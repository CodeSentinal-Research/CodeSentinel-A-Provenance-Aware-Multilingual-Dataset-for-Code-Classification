#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_set<std::string> starts;
        for (const auto& p : paths) starts.insert(p[0]);

        for (const auto& p : paths) {
            if (!starts.count(p[1])) return p[1];
        }
        return "";
    }
};