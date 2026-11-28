#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (cnt1 > 0 && x == c1) cnt1++;
            else if (cnt2 > 0 && x == c2) cnt2++;
            else if (cnt1 == 0) { c1 = x; cnt1 = 1; }
            else if (cnt2 == 0) { c2 = x; cnt2 = 1; }
            else { cnt1--; cnt2--; }
        }

        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == c1) cnt1++;
            else if (x == c2) cnt2++;
        }

        std::vector<int> res;
        int n = nums.size();
        if (cnt1 > n / 3) res.push_back(c1);
        if (c2 != c1 && cnt2 > n / 3) res.push_back(c2);
        return res;
    }
};