#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minMoves(std::vector<int>& nums, int k) {
        std::vector<int> p;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) p.push_back(i);
        }
        int n = p.size();
        std::vector<long long> presum(n + 1, 0);
        for (int i = 0; i < n; i++) presum[i + 1] = presum[i] + p[i];

        long long ans = LLONG_MAX;
        int radius = (k - 1) / 2;

        for (int i = radius; i < n - k + radius + 1; i++) {
            long long right = presum[i + k - radius] - presum[i + 1];
            long long left = presum[i] - presum[i - radius];
            ans = std::min(ans, right - left);
        }

        long long offset = (long long)radius * (radius + 1);
        if (k % 2 == 0) offset += (radius + 1);
        return ans - offset;
    }
};