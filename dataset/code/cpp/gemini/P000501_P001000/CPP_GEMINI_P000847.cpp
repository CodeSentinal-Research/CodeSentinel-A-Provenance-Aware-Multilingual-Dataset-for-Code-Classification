#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long maxRunTime(int n, std::vector<int>& batteries) {
        long long total = std::accumulate(batteries.begin(), batteries.end(), 0LL);
        long long left = 1, right = total / n;
        long long ans = 0;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long long mid = left + (right - left) / 2;
            long long curr = 0;
            for (long long b : batteries) {
                curr += std::min(b, mid);
            }
            if (curr >= mid * n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};