#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumTastiness(int* price, int priceSize, int k) {
    qsort(price, priceSize, sizeof(int), cmpInt);
    int left = 0, right = price[priceSize - 1] - price[0];
    int ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int count = 1, last = price[0];
        for (int i = 1; i < priceSize; i++) {
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