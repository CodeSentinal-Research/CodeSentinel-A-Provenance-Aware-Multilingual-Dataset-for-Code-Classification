#include <stdbool.h>
#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isPossibleDivide(int* nums, int numsSize, int k) {
    if (numsSize % k != 0) return false;
    qsort(nums, numsSize, sizeof(int), cmpInt);

    bool* visited = (bool*)calloc(numsSize, sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        int nextVal = nums[i] + 1;
        int found = 1;

        for (int j = i + 1; j < numsSize && found < k; j++) {
            if (!visited[j] && nums[j] == nextVal) {
                visited[j] = true;
                nextVal++;
                found++;
            }
        }
        if (found < k) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}