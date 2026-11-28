#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* sequentialDigits(int low, int high, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    int count = 0;

    char lowStr[16], highStr[16];
    sprintf(lowStr, "%d", low);
    sprintf(highStr, "%d", high);
    int lowLen = strlen(lowStr), highLen = strlen(highStr);

    for (int len = lowLen; len <= highLen; len++) {
        for (int start = 1; start <= 10 - len; start++) {
            int num = 0;
            for (int d = start; d < start + len; d++) {
                num = num * 10 + d;
            }
            if (num >= low && num <= high) {
                res[count++] = num;
            }
        }
    }

    *returnSize = count;
    return res;
}