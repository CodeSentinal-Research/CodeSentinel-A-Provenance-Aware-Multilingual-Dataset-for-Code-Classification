#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpLongest(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmpLongest);

    int longest = 1, streak = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) {
            streak++;
        } else {
            streak = 1;
        }
        longest = MAX(longest, streak);
    }
    return longest;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    int* nums = (int*)malloc(N * sizeof(int));
    if (nums == NULL) return 1;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    
    int result = longestConsecutive(nums, N);
    printf("%d\n", result);
    
    free(nums);
    return 0;
}