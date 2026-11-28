#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        std::unordered_map<int, long long> map;

        for (int i = 0; i < n; i++) {
            map[nums[i] - i]++;
        }

        long long goodPairs = 0;
        for (const auto& [_, cnt] : map) {
            goodPairs += cnt * (cnt - 1) / 2;
        }
        return totalPairs - goodPairs;
    }
};