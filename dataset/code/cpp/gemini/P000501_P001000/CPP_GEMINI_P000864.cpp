#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < (int)nums.size(); i++) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};