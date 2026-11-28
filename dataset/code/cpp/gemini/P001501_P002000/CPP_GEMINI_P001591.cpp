#include <vector>

class NumArray {
    std::vector<int> prefix;
public:
    NumArray(std::vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (size_t i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};