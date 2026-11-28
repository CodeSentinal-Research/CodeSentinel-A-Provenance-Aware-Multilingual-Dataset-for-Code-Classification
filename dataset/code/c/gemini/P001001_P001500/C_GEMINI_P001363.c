#include <stdlib.h>
#include <string.h>

void backtrackBin(int n, char* cur, int len, char** res, int* count) {
    if (len == n) {
        cur[len] = '\0';
        res[*count] = strdup(cur);
        (*count)++;
        return;
    }
    cur[len] = '1';
    backtrackBin(n, cur, len + 1, res, count);

    if (len == 0 || cur[len - 1] != '0') {
        cur[len] = '0';
        backtrackBin(n, cur, len + 1, res, count);
    }
}

char** validStrings(int n, int* returnSize) {
    char** res = (char**)malloc(5000 * sizeof(char*));
    char cur[n + 1];
    int count = 0;
    backtrackBin(n, cur, 0, res, &count);
    *returnSize = count;
    return res;
}