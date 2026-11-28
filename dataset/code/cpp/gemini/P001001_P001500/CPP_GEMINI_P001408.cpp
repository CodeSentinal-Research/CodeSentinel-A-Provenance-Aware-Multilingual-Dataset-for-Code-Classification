#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> recoverArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size() / 2;

        for (size_t i = 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[0];
            if (diff <= 0 || diff % 2 != 0) continue;
            int k = diff / 2;

            std::unordered_map<int, int> map;
            for (int x : nums) map[x]++;

            std::vector<int> res;
            for (int x : nums) {
                if (map[x] == 0) continue;
                if (map[x + 2 * k] == 0) break;

                res.push_back(x + k);
                map[x]--;
                map[x + 2 * k]--;
            }

            if ((int)res.size() == n) return res;
        }
        return {};
    }
};