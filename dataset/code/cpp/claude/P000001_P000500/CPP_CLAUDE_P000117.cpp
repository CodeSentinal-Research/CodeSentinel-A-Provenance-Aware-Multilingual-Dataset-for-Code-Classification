#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());
        return seen.size() != nums.size();
    }
};
