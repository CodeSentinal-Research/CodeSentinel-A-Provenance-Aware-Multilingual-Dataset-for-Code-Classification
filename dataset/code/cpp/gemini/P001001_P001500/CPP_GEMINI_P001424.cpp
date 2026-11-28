#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> count;
        for (int x : arr) count[x]++;

        std::unordered_set<int> set;
        for (const auto& [_, cnt] : count) {
            if (!set.insert(cnt).second) return false;
        }
        return true;
    }
};