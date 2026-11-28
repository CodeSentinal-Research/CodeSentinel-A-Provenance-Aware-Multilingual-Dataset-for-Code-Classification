int findPeakElement(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1]) r = mid;
        else l = mid + 1;
    }
    return l;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int peakIndex = findPeakElement(nums, n);
    printf("%d\n", peakIndex);

    free(nums);
    return 0;
}
