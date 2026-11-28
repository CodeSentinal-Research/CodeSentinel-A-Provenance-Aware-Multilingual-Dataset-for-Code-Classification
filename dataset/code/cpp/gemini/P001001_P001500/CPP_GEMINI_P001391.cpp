#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        count[0] = 1;
        int prefix = 0, ans = 0;

        for (int x : nums) {
            prefix += x;
            if (count.count(prefix - k)) ans += count[prefix - k];
            count[prefix]++;
        }
        return ans;
    }
};