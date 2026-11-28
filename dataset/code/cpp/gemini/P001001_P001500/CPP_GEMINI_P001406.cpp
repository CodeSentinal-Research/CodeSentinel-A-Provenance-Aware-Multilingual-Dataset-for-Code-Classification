#include <vector>
#include <unordered_map>

class Solution {
public:
    int mostFrequent(std::vector<int>& nums, int key) {
        std::unordered_map<int, int> map;
        int maxCount = 0, bestTarget = 0;

        for (size_t i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];
                int cnt = ++map[target];
                if (cnt > maxCount) {
                    maxCount = cnt;
                    bestTarget = target;
                }
            }
        }
        return bestTarget;
    }
};