#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    bool isPossibleDivide(std::vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        std::map<int, int> count;
        for (int x : nums) count[x]++;

        for (const auto& [x, freq] : count) {
            if (freq > 0) {
                for (int i = 1; i < k; i++) {
                    if (count[x + i] < freq) return false;
                    count[x + i] -= freq;
                }
            }
        }
        return true;
    }
};