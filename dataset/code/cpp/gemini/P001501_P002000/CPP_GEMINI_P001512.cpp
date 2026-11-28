#include <vector>
#include <unordered_map>

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        std::unordered_map<int, int> count;
        count[0] = 1;
        int curSum = 0, ans = 0;

        for (int x : nums) {
            curSum += x;
            if (count.count(curSum - goal)) ans += count[curSum - goal];
            count[curSum]++;
        }
        return ans;
    }
};