#include <stdbool.h>
#include <stdlib.h>

bool isPossible(int* nums, int numsSize) {
    int minVal = nums[0], maxVal = nums[numsSize - 1];
    int offset = -minVal + 1;
    int range = maxVal - minVal + 5;

    int* count = (int*)calloc(range, sizeof(int));
    int* end = (int*)calloc(range, sizeof(int));

    for (int i = 0; i < numsSize; i++) count[nums[i] + offset]++;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i] + offset;
        if (count[x] == 0) continue;
        count[x]--;
        if (end[x - 1] > 0) {
            end[x - 1]--;
            end[x]++;
        } else if (count[x + 1] > 0 && count[x + 2] > 0) {
            count[x + 1]--;
            count[x + 2]--;
            end[x + 2]++;
        } else {
            free(count);
            free(end);
            return false;
        }
    }
    free(count);
    free(end);
    return true;
}