#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        size_t k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
};