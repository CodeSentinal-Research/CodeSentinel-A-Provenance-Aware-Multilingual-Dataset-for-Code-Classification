#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> rotateRight(std::vector<int> nums, int k) {
        int n = nums.size();
        if (!n) return nums;
        k = ((k % n) + n) % n;
        std::rotate(nums.begin(), nums.begin() + (n - k), nums.end());
        return nums;
    }
};
