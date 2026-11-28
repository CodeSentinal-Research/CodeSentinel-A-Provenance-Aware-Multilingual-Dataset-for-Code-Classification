#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        std::unordered_set<int> unique(nums.begin(), nums.end());
        size_t k = unique.size();

        std::unordered_map<int, int> count;
        int ans = 0, l = 0;

        for (size_t r = 0; r < nums.size(); r++) {
            count[nums[r]]++;
            while (count.size() == k) {
                ans += nums.size() - r;
                if (--count[nums[l]] == 0) count.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};