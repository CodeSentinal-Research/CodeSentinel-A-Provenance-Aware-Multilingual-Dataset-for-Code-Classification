#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmpInt);
    qsort(s, sSize, sizeof(int), cmpInt);
    int childPtr = 0, cookiePtr = 0;

    while (childPtr < gSize && cookiePtr < sSize) {
        if (s[cookiePtr] >= g[childPtr]) {
            childPtr++;
        }
        cookiePtr++;
    }
    return childPtr;
}