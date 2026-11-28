#include <vector>
#include <algorithm>

class Solution {
public:
    long long minimumTime(std::vector<int>& time, int totalTrips) {
        long long minT = *std::min_element(time.begin(), time.end());
        long long l = 1, r = minT * totalTrips, ans = r;

        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            long long trips = 0;
            for (int t : time) {
                trips += mid / t;
            }

            if (trips >= totalTrips) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};