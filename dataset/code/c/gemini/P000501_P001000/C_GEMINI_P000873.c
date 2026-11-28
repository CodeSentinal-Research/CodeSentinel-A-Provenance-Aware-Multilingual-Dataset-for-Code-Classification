#include <stdlib.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    *returnSize = encodedSize + 1;
    int* res = (int*)malloc((encodedSize + 1) * sizeof(int));
    res[0] = first;
    for (int i = 0; i < encodedSize; i++) {
        res[i + 1] = res[i] ^ encoded[i];
    }
    return res;
}