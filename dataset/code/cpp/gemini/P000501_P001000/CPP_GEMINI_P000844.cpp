#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumTastiness(std::vector<int>& price, int k) {
        std::sort(price.begin(), price.end());
        int left = 0, right = price.back() - price.front();
        int ans = 0;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int count = 1, last = price[0];
            for (size_t i = 1; i < price.size(); i++) {
                if (price[i] - last >= mid) {
                    count++;
                    last = price[i];
                }
            }
            if (count >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};