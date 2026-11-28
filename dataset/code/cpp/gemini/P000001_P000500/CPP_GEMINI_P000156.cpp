#include <vector>
#include <algorithm>

class Solution {
public:
    int maxConsecutiveZeros(std::vector<int>& nums) {
        int maxZeros = 0, curZeros = 0;
        for (int x : nums) {
            if (x == 0) {
                curZeros++;
                maxZeros = std::max(maxZeros, curZeros);
            } else {
                curZeros = 0;
            }
        }
        return maxZeros;
    }
};