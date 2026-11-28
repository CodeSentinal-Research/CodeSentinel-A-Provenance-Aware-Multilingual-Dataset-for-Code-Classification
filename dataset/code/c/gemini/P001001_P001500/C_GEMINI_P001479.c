#include <stdlib.h>

// Sorts the input array into ordered sequence.
int cmpIntUnsorted(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Sorts the input array into ordered sequence.
int findUnsortedSubarray(int* nums, int numsSize) {
    int* sorted = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) sorted[i] = nums[i];
    qsort(sorted, numsSize, sizeof(int), cmpIntUnsorted);

    int l = 0, r = numsSize - 1;
    while (l < numsSize && nums[l] == sorted[l]) l++;
    while (r > l && nums[r] == sorted[r]) r--;

    free(sorted);
    return r > l ? r - l + 1 : 0;
}