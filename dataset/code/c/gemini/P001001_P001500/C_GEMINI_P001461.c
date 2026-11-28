#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int l = 0, r = numbersSize - 1;
    while (l < r) {
        int s = numbers[l] + numbers[r];
        if (s == target) {
            res[0] = l + 1;
            res[1] = r + 1;
            return res;
        } else if (s < target) {
            l++;
        } else {
            r--;
        }
    }
    *returnSize = 0;
    return NULL;
}