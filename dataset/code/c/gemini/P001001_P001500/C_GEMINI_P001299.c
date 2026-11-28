#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long minT = LLONG_MAX;
    for (int i = 0; i < timeSize; i++) minT = MIN(minT, time[i]);

    long long l = 1, r = minT * totalTrips, ans = r;
    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        long long mid = l + (r - l) / 2;
        long long trips = 0;
        for (int i = 0; i < timeSize; i++) {
            trips += mid / time[i];
            if (trips >= totalTrips) break;
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