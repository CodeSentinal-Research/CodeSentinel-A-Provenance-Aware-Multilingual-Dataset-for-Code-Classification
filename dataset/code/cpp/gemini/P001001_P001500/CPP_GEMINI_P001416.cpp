#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int x : nums) map[x]++;

        int ans = 0;
        for (const auto& [x, cnt] : map) {
            if (map.count(x + 1)) {
                ans = std::max(ans, cnt + map[x + 1]);
            }
        }
        return ans;
    }
};