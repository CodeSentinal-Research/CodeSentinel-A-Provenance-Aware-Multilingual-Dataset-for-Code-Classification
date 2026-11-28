#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> unionArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s(nums1.begin(), nums1.end());
        for (int x : nums2) s.insert(x);
        return std::vector<int>(s.begin(), s.end());
    }
};