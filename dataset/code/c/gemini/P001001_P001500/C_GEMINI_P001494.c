#include <stdlib.h>
#include <string.h>

int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    int* res = (int*)malloc((n + 1) * sizeof(int));
    int lo = 0, hi = n;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') res[i] = lo++;
        else res[i] = hi--;
    }
    res[n] = lo;
    *returnSize = n + 1;
    return res;
}