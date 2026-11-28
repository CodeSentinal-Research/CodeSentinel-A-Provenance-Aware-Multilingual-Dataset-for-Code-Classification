#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long putMarbles(std::vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || k == n) return 0;

        std::vector<long long> pairWeights(n - 1);
        for (int i = 0; i < n - 1; i++) {
            pairWeights[i] = (long long)weights[i] + weights[i + 1];
        }
        std::sort(pairWeights.begin(), pairWeights.end());

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairWeights[i];
            maxSum += pairWeights[n - 2 - i];
        }
        return maxSum - minSum;
    }
};