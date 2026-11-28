// P000190: Find Duplicate in Array of N+1 Elements
// Approach: index-marking (negate values at visited indices)
// Different from P000137 which uses Floyd's cycle detection
#include <vector>
#include <cmath>
class Solution {
public:
    int findDuplicateInNPlusOne(std::vector<int>& nums) {
        int duplicate = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = std::abs(nums[i]);
            if (nums[idx] < 0) {
                duplicate = idx;
                break;
            }
            nums[idx] = -nums[idx];
        }
        for (int i = 0; i < n; i++)
            if (nums[i] < 0) nums[i] = -nums[i];
        return duplicate;
    }
};
