#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int x : nums) {
            if (set.count(x)) return true;
            set.insert(x);
        }
        return false;
    }
};