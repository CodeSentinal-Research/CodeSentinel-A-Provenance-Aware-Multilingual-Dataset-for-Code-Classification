#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s1(nums1.begin(), nums1.end());
        std::unordered_set<int> s2(nums2.begin(), nums2.end());

        std::vector<int> diff1, diff2;
        for (int n : s1) if (!s2.count(n)) diff1.push_back(n);
        for (int n : s2) if (!s1.count(n)) diff2.push_back(n);

        return {diff1, diff2};
    }
};