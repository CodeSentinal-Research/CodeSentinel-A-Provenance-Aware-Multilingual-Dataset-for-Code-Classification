#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int l = 0, ans = 1;
        long long total = 0;

        for (size_t r = 0; r < nums.size(); r++) {
            total += nums[r];
            while ((long long)nums[r] * (r - l + 1) - total > k) {
                total -= nums[l++];
            }
            ans = std::max(ans, (int)(r - l + 1));
        }
        return ans;
    }
};