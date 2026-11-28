#include <vector>
#include <unordered_set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s(nums1.begin(), nums1.end());
        std::unordered_set<int> res;
        for (int x : nums2) if (s.count(x)) res.insert(x);
        return std::vector<int>(res.begin(), res.end());
    }
};
