#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoOddNum(std::vector<int>& arr, int n) {
        int xorAll = 0;
        for (int v : arr) xorAll ^= v;

        int diffBit = xorAll & (-xorAll);
        int x = 0, y = 0;
        for (int v : arr) {
            if (v & diffBit) x ^= v;
            else y ^= v;
        }

        return {std::max(x, y), std::min(x, y)};
    }
};