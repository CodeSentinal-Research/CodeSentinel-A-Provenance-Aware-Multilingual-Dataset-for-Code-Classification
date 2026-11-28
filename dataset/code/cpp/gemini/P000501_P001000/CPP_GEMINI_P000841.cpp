#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumCandies(std::vector<int>& candies, long long k) {
        int left = 1, right = *std::max_element(candies.begin(), candies.end());
        int ans = 0;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            long long children = 0;
            for (int c : candies) {
                children += c / mid;
            }
            if (children >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};