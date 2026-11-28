#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed) {
        if (changed.size() % 2 != 0) return {};
        std::sort(changed.begin(), changed.end());

        std::unordered_map<int, int> map;
        for (int x : changed) map[x]++;

        std::vector<int> res;
        for (int x : changed) {
            if (map[x] == 0) continue;
            if (map[2 * x] == 0) return {};

            res.push_back(x);
            map[x]--;
            map[2 * x]--;
        }
        return res;
    }
};