#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumSumSubarray(int k, std::vector<int>& arr) {
        long long curSum = 0;
        for (int i = 0; i < k; i++) curSum += arr[i];
        long long maxSum = curSum;

        for (size_t i = k; i < arr.size(); i++) {
            curSum += arr[i] - arr[i - k];
            maxSum = std::max(maxSum, curSum);
        }
        return maxSum;
    }
};