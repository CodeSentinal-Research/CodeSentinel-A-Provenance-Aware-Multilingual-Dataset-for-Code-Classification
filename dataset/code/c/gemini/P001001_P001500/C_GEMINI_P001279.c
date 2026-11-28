#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

char* getSmallestString(int n, int k) {
    char* res = (char*)malloc((n + 1) * sizeof(char));
    memset(res, 'a', n);
    res[n] = '\0';
    k -= n;

    for (int i = n - 1; i >= 0 && k > 0; i--) {
        int add = MIN(25, k);
        res[i] = 'a' + add;
        k -= add;
    }
    return res;
}