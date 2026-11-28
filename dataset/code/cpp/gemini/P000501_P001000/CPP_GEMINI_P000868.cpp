#include <vector>

class Solution {
public:
    int totalHammingDistance(std::vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            int ones = 0;
            for (int x : nums) {
                ones += (x >> i) & 1;
            }
            total += ones * (n - ones);
        }
        return total;
    }
};