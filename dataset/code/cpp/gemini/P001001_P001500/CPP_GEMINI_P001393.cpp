#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = -1;
        int prefix = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % k;
            if (map.count(prefix)) {
                if ((int)i - map[prefix] >= 2) return true;
            } else {
                map[prefix] = i;
            }
        }
        return false;
    }
};