#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> resSet;
        for (int n : nums2) {
            if (set1.count(n)) resSet.insert(n);
        }
        return std::vector<int>(resSet.begin(), resSet.end());
    }
};