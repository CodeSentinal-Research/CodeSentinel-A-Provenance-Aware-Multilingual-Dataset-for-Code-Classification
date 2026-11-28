#include <vector>
#include <unordered_map>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        int count = 0;
        for (int x : nums) {
            count += map[target - x];
            map[x]++;
        }
        return count;
    }
};