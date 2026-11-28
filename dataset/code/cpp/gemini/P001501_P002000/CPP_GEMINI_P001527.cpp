#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int ans = INT_MAX;
        for (int size = l; size <= r; size++) {
            for (int i = 0; i <= n - size; i++) {
                int sum = prefix[i + size] - prefix[i];
                if (sum > 0) ans = std::min(ans, sum);
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};