#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        long long ans = 0;
        long long total = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            total += nums[i];
            ans = std::max(ans, (total + i) / (i + 1));
        }
        return (int)ans;
    }
};