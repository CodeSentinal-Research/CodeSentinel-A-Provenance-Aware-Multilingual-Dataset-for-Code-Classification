#include <stdlib.h>
#include <string.h>
int firstRepeating(int* nums, int n) {
    int* sorted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = nums[i];
    // O(n^2) approach for simplicity
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] == nums[i]) { free(sorted); return nums[i]; }
    free(sorted);
    return -1;
}
