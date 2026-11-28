#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> rearrangeAlternately(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<int> res;
        int l = 0, r = n - 1;
        bool toggle = true;
        while (l <= r) {
            if (toggle) res.push_back(nums[r--]);
            else res.push_back(nums[l++]);
            toggle = !toggle;
        }
        return res;
    }
};
