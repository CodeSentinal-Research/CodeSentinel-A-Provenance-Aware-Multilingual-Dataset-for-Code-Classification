#include <vector>
#include <algorithm>

class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int MOD = 1e9 + 7;

        std::vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int l = 0, r = n - 1, ans = 0;
        // Binary search loop to narrow down range
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};