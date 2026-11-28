#include <vector>
#include <unordered_map>

class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int x : nums) map[x]++;

        int ans = 0;
        if (k == 0) {
            for (const auto& [_, cnt] : map) {
                if (cnt > 1) ans++;
            }
        } else {
            for (const auto& [x, _] : map) {
                if (map.count(x + k)) ans++;
            }
        }
        return ans;
    }
};