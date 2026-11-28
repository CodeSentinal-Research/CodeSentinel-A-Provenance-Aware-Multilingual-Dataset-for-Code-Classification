#include <vector>

class Solution {
public:
    long long countAlternatingSubarrays(std::vector<int>& nums) {
        long long ans = 1, curLen = 1;

        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                curLen++;
            } else {
                curLen = 1;
            }
            ans += curLen;
        }
        return ans;
    }
};