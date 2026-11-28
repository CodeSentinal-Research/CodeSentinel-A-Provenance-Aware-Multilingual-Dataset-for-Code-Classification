#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpStr(const void* a, const void* b) {
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    char ab[64], ba[64];
    sprintf(ab, "%s%s", s1, s2);
    sprintf(ba, "%s%s", s2, s1);
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    char** strs = (char**)malloc(numsSize * sizeof(char*));
    int totalLen = 0;
    for (int i = 0; i < numsSize; i++) {
        strs[i] = (char*)malloc(16 * sizeof(char));
        sprintf(strs[i], "%d", nums[i]);
        totalLen += strlen(strs[i]);
    }
    qsort(strs, numsSize, sizeof(char*), cmpStr);

    if (strcmp(strs[0], "0") == 0) {
        return "0";
    }

    char* res = (char*)malloc((totalLen + 1) * sizeof(char));
    res[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(res, strs[i]);
        free(strs[i]);
    }
    free(strs);
    return res;
}