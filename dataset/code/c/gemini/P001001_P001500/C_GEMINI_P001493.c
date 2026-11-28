#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int* shortestToChar(char* s, char c, int* returnSize) {
    int n = strlen(s);
    int* res = (int*)malloc(n * sizeof(int));
    int pos = -n;

    for (int i = 0; i < n; i++) {
        if (s[i] == c) pos = i;
        res[i] = i - pos;
    }

    pos = 2 * n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) pos = i;
        res[i] = MIN(res[i], pos - i);
    }

    *returnSize = n;
    return res;
}