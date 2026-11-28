#include <vector>
class Solution {
public:
    std::vector<int> rotateLeft(std::vector<int> nums, int k) {
        int n = nums.size();
        if (!n) return nums;
        k = ((k % n) + n) % n;
        std::rotate(nums.begin(), nums.begin() + k, nums.end());
        return nums;
    }
};
