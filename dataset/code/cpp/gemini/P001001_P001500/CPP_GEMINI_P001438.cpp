#include <vector>
#include <unordered_map>

class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        std::vector<int> count(501, 0);
        for (int x : nums) count[x]++;
        for (int c : count) {
            if (c % 2 != 0) return false;
        }
        return true;
    }
};