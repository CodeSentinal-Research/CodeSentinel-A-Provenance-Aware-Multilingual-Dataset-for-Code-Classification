#include <stdlib.h>

int longestSubarray(int* nums, int numsSize, int limit) {
    int* maxDq = (int*)malloc(numsSize * sizeof(int));
    int* minDq = (int*)malloc(numsSize * sizeof(int));
    int maxH = 0, maxT = 0, minH = 0, minT = 0;
    int l = 0;

    for (int r = 0; r < numsSize; r++) {
        int num = nums[r];
        while (maxT > maxH && num > maxDq[maxT - 1]) maxT--;
        while (minT > minH && num < minDq[minT - 1]) minT--;
        maxDq[maxT++] = num;
        minDq[minT++] = num;

        if (maxDq[maxH] - minDq[minH] > limit) {
            if (maxDq[maxH] == nums[l]) maxH++;
            if (minDq[minH] == nums[l]) minH++;
            l++;
        }
    }
    free(maxDq);
    free(minDq);
    return numsSize - l;
}