#include <vector>

class Solution {
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n);
        int pos = 0, neg = 1;

        for (int x : nums) {
            if (x > 0) {
                res[pos] = x;
                pos += 2;
            } else {
                res[neg] = x;
                neg += 2;
            }
        }
        return res;
    }
};