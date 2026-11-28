#include <vector>
#include <set>
class Solution {
public:
    std::vector<int> unionArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> s(nums1.begin(), nums1.end());
        s.insert(nums2.begin(), nums2.end());
        return std::vector<int>(s.begin(), s.end());
    }
};
