#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> allPairs(int target, std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<std::vector<int>> res;

        for (int y : nums2) {
            int x = target - y;
            if (set1.count(x)) {
                res.push_back({x, y});
            }
        }
        std::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        return res;
    }
};