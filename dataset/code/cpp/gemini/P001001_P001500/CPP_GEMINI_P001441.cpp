#include <vector>
#include <unordered_map>

class Solution {
public:
    int countKDifference(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int ans = 0;

        for (int x : nums) {
            if (count.count(x - k)) ans += count[x - k];
            if (count.count(x + k)) ans += count[x + k];
            count[x]++;
        }
        return ans;
    }
};