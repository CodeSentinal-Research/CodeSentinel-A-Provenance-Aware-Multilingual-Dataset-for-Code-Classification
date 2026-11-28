#include <vector>
class Solution {
public:
    void sortArray012(std::vector<int>& nums) {
        int lo=0, mid=0, hi=nums.size()-1;
        while (mid<=hi) {
            if (nums[mid]==0) std::swap(nums[lo++], nums[mid++]);
            else if (nums[mid]==1) mid++;
            else std::swap(nums[mid], nums[hi--]);
        }
    }
};
