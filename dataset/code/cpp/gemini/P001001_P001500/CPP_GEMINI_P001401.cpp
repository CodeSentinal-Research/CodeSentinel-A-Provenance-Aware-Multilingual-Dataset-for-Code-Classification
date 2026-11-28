#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubArrayLen(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int prefix = 0, maxLen = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if (map.count(prefix - k)) {
                maxLen = std::max(maxLen, (int)i - map[prefix - k]);
            }
            if (!map.count(prefix)) {
                map[prefix] = i;
            }
        }
        return maxLen;
    }
};