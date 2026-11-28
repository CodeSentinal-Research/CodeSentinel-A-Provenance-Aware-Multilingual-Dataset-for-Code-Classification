#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        count[0] = 1;
        int curSum = 0, ans = 0;

        for (int x : nums) {
            curSum += x;
            if (count.count(curSum - k)) ans += count[curSum - k];
            count[curSum]++;
        }
        return ans;
    }
};