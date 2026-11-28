#include <vector>
#include <algorithm>
#include <unordered_set>
class Solution {
public:
    bool containsContiguous(std::vector<int>& nums) {
        if (nums.empty()) return true;
        std::unordered_set<int> s(nums.begin(), nums.end());
        if (s.size() != nums.size()) return false;
        int mn = *std::min_element(nums.begin(),nums.end());
        int mx = *std::max_element(nums.begin(),nums.end());
        return mx - mn == (int)nums.size()-1;
    }
};
