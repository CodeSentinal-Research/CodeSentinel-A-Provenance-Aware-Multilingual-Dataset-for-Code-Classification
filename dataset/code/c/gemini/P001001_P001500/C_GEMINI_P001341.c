#include <stdlib.h>
#include <stdio.h>

int bitCountWatch(int n) {
    int c = 0;
    while (n > 0) { c += (n & 1); n >>= 1; }
    return c;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** res = (char**)malloc(1000 * sizeof(char*));
    int count = 0;

    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (bitCountWatch(h) + bitCountWatch(m) == turnedOn) {
                res[count] = (char*)malloc(10 * sizeof(char));
                sprintf(res[count], "%d:%02d", h, m);
                count++;
            }
        }
    }
    *returnSize = count;
    return res;
}