#include <vector>
#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::vector<int> count(101, 0);
        int ans = 0;

        for (int x : nums) {
            ans += count[x]++;
        }
        return ans;
    }
};