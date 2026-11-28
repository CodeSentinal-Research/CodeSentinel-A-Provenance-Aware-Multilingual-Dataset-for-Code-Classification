#include <vector>
class Solution {
public:
    std::vector<int> subarrayWithGivenSum(std::vector<int>& nums, long long target) {
        int l = 0; long long cur = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            cur += nums[r];
            while (cur > target && l <= r) cur -= nums[l++];
            if (cur == target) return {l, r};
        }
        return {};
    }
};
