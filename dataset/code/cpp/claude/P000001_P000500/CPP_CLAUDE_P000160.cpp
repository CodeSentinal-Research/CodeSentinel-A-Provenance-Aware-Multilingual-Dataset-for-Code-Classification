#include <vector>
#include <unordered_set>
#include <optional>
class Solution {
public:
    std::vector<int> findPair(std::vector<int>& nums, int target) {
        std::unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(target - x)) return {target - x, x};
            seen.insert(x);
        }
        return {};
    }
};
