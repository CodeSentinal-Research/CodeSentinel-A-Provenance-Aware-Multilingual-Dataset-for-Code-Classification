#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    void sortColors(std::vector<int>& nums) {
        int l = 0, curr = 0, r = (int)nums.size() - 1;
        while (curr <= r) {
            if (nums[curr] == 0) {
                std::swap(nums[l++], nums[curr++]);
            } else if (nums[curr] == 2) {
                std::swap(nums[curr], nums[r--]);
            } else {
                curr++;
            }
        }
    }
};