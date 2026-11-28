#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        long long xorAll = 0;
        for (int x : nums) xorAll ^= x;
        long long diff = xorAll & (-xorAll);
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & diff) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};