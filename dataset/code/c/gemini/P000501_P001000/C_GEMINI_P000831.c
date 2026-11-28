#include <limits.h>

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long long)m * k > bloomDaySize) return -1;
    int left = INT_MAX, right = 0;
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] < left) left = bloomDay[i];
        if (bloomDay[i] > right) right = bloomDay[i];
    }
    int ans = -1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < bloomDaySize; i++) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        if (bouquets >= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}