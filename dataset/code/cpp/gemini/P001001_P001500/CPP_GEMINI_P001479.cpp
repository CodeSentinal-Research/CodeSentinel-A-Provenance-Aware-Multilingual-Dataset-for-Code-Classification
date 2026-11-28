#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    int findUnsortedSubarray(std::vector<int>& nums) {
        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());

        int l = 0, r = (int)nums.size() - 1;
        while (l < (int)nums.size() && nums[l] == sorted[l]) l++;
        while (r > l && nums[r] == sorted[r]) r--;

        return r > l ? r - l + 1 : 0;
    }
};