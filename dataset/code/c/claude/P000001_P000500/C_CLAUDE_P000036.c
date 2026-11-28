#include <stdlib.h>
#include <string.h>

char* decToBinary(int n) {
    if (n == 0) {
        char* zero = (char*)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }
    char buf[64];
    int idx = 0;
    unsigned int un = (unsigned int)n;
    while (un > 0) {
        buf[idx++] = (un % 2) + '0';
        un /= 2;
    }
    char* res = (char*)malloc((idx + 1) * sizeof(char));
    for (int i = 0; i < idx; i++) {
        res[i] = buf[idx - 1 - i];
    }
    res[idx] = '\0';
    return res;
}
