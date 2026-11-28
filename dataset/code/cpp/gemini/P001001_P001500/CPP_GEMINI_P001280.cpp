#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1;
        int patches = 0;
        size_t i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};