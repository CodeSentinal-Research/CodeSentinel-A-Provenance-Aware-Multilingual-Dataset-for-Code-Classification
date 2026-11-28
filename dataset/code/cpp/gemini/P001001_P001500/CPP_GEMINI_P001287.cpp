#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    bool canDivide(const std::vector<int>& sweetness, int k, int target) {
        int pieces = 0, curSum = 0;
        for (int s : sweetness) {
            curSum += s;
            if (curSum >= target) {
                pieces++;
                curSum = 0;
            }
        }
        return pieces >= k + 1;
    }
public:
    int maximizeSweetness(std::vector<int>& sweetness, int k) {
        int minVal = *std::min_element(sweetness.begin(), sweetness.end());
        int total = std::accumulate(sweetness.begin(), sweetness.end(), 0);

        int l = minVal, r = total / (k + 1), ans = l;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (canDivide(sweetness, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};