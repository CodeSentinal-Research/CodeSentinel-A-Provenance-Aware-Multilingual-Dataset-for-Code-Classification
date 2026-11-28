#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxLength(int* nums, int numsSize) {
    int* map = (int*)malloc((2 * numsSize + 1) * sizeof(int));
    for (int i = 0; i < 2 * numsSize + 1; i++) map[i] = -2;

    int offset = numsSize;
    map[offset] = -1;
    int prefix = 0, maxLen = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix += (nums[i] == 1 ? 1 : -1);
        if (map[offset + prefix] != -2) {
            maxLen = MAX(maxLen, i - map[offset + prefix]);
        } else {
            map[offset + prefix] = i;
        }
    }
    free(map);
    return maxLen;
}