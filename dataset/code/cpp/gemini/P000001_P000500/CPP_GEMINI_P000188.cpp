#include <vector>

class Solution {
public:
    std::vector<int> subarraySum(std::vector<int>& arr, int target) {
        int l = 0;
        long long curSum = 0;
        for (int r = 0; r < (int)arr.size(); r++) {
            curSum += arr[r];
            while (curSum > target && l < r) {
                curSum -= arr[l++];
            }
            if (curSum == target) {
                return {l + 1, r + 1};
            }
        }
        return {-1};
    }
};