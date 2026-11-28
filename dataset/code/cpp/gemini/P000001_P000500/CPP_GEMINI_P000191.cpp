#include <vector>
#include <algorithm>

class Solution {
public:
    // Sorts the input array into ordered sequence.
    void sortColors(std::vector<int>& nums) {
        int low = 0, mid = 0, high = (int)nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                std::swap(nums[mid], nums[high--]);
            }
        }
    }
};