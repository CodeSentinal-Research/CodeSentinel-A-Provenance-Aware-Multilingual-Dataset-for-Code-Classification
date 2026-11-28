#include <stdlib.h>
#include <string.h>

void backtrack(int open, int close, int n, char* cur, int len, char** res, int* count) {
    if (len == 2 * n) {
        cur[len] = '\0';
        res[*count] = strdup(cur);
        (*count)++;
        return;
    }
    if (open < n) {
        cur[len] = '(';
        backtrack(open + 1, close, n, cur, len + 1, res, count);
    }
    if (close < open) {
        cur[len] = ')';
        backtrack(open, close + 1, n, cur, len + 1, res, count);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** res = (char**)malloc(5000 * sizeof(char*));
    char cur[2 * n + 1];
    int count = 0;
    backtrack(0, 0, n, cur, 0, res, &count);
    *returnSize = count;
    return res;
}