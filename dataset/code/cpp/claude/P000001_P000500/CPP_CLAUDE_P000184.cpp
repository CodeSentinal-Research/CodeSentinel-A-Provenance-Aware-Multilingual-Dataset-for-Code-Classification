#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int longestSubarrayWithSumK(std::vector<int>& nums, long long k) {
        std::unordered_map<long long,int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefix += nums[i];
            if (mp.count(prefix - k))
                best = std::max(best, i - mp[prefix - k]);
            if (!mp.count(prefix)) mp[prefix] = i;
        }
        return best;
    }
};
