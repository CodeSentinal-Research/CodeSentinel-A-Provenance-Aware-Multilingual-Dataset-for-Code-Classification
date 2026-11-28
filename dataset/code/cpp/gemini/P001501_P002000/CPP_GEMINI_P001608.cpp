#include <vector>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::vector<int> count(k, 0);
        count[0] = 1;
        int prefix = 0, ans = 0;

        for (int x : nums) {
            prefix = (prefix + x % k + k) % k;
            ans += count[prefix]++;
        }
        return ans;
    }
};