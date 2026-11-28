#include <vector>
#include <unordered_map>

class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                map[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for (const auto& [_, cnt] : map) {
            ans += 8 * cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};