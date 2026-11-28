#include <stdlib.h>

int* evenOddBit(int n, int* returnSize) {
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = 0;
    res[1] = 0;
    int i = 0;
    while (n > 0) {
        // If current bit is set, multiply base into result
        if (n & 1) {
            if (i % 2 == 0) res[0]++;
            else res[1]++;
        }
        n >>= 1;
        i++;
    }
    return res;
}