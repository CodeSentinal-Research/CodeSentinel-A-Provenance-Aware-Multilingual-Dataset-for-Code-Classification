#include <stdlib.h>
#include <string.h>

int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* sortString(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    strcpy(res, s);
    qsort(res, n, sizeof(char), cmpChar);
    return res;
}