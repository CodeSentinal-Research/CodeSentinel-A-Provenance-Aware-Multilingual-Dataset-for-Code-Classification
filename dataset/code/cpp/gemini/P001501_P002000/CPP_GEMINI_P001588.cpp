#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        std::vector<int> count(nums.size() + 1, 0);
        count[0] = 1;
        int curOdds = 0, ans = 0;

        for (int x : nums) {
            curOdds += (x % 2 != 0 ? 1 : 0);
            if (curOdds >= k) ans += count[curOdds - k];
            count[curOdds]++;
        }
        return ans;
    }
};