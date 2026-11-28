#include <vector>
#include <numeric>

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        int total = std::accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false;

        int target = total / 3;
        int curSum = 0, count = 0;

        for (int x : arr) {
            curSum += x;
            if (curSum == target) {
                count++;
                curSum = 0;
            }
        }
        return count >= 3;
    }
};