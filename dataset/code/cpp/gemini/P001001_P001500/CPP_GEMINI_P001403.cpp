#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> res;
        for (size_t i = 0; i < l.size(); i++) {
            std::vector<int> sub(nums.begin() + l[i], nums.begin() + r[i] + 1);
            std::sort(sub.begin(), sub.end());

            bool isArith = true;
            int diff = sub[1] - sub[0];
            for (size_t j = 2; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != diff) {
                    isArith = false;
                    break;
                }
            }
            res.push_back(isArith);
        }
        return res;
    }
};