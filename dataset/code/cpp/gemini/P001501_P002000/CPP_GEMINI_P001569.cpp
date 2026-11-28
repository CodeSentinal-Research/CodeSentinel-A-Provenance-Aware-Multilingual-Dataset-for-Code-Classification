#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        int l = 0, curSum = 0, maxSum = 0;

        for (int num : nums) {
            while (seen.count(num)) {
                seen.erase(nums[l]);
                curSum -= nums[l++];
            }
            seen.insert(num);
            curSum += num;
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};