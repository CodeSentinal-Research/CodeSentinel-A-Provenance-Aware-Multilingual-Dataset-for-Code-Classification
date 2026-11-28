#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int prefix = 0, maxLen = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 1 ? 1 : -1);
            if (map.count(prefix)) {
                maxLen = std::max(maxLen, (int)i - map[prefix]);
            } else {
                map[prefix] = i;
            }
        }
        return maxLen;
    }
};