#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int longestSubarrayEqual01(std::vector<int>& nums) {
        std::unordered_map<int,int> mp;
        mp[0] = -1;
        int prefix = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefix += (nums[i]==1) ? 1 : -1;
            if (mp.count(prefix)) best = std::max(best, i - mp[prefix]);
            else mp[prefix] = i;
        }
        return best;
    }
};
