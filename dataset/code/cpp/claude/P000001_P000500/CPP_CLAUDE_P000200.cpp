#include <vector>
class Solution {
public:
    std::vector<int> findTwoOddOccurrences(std::vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int bit = xorAll & (-xorAll);
        int a=0, b=0;
        for (int x : nums) {
            if (x & bit) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};
