#include <vector>
#include <algorithm>

class Solution {
public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int left = 1, right = *std::max_element(quantities.begin(), quantities.end());
        int ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            long long needed = 0;
            for (int q : quantities) {
                needed += (q + mid - 1) / mid;
            }
            if (needed <= n) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};