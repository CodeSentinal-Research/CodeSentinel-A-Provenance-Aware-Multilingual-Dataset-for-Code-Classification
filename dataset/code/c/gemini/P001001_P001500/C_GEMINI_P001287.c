#include <stdbool.h>
#include <limits.h>

bool canDivideSweet(int* sweetness, int n, int k, int target) {
    int pieces = 0, curSum = 0;
    for (int i = 0; i < n; i++) {
        curSum += sweetness[i];
        if (curSum >= target) {
            pieces++;
            curSum = 0;
        }
    }
    return pieces >= k + 1;
}

int maximizeSweetness(int* sweetness, int sweetnessSize, int k) {
    int minVal = INT_MAX, total = 0;
    for (int i = 0; i < sweetnessSize; i++) {
        if (sweetness[i] < minVal) minVal = sweetness[i];
        total += sweetness[i];
    }

    int l = minVal, r = total / (k + 1), ans = l;
    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (canDivideSweet(sweetness, sweetnessSize, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}