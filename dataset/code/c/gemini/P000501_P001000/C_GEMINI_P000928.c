#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1, j = strlen(b) - 1, carry = 0;
    int maxLen = (i > j ? i : j) + 3;
    char* res = (char*)malloc(maxLen * sizeof(char));
    int idx = 0;
    while (i >= 0 || j >= 0 || carry) {
        int total = carry;
        if (i >= 0) total += (a[i--] - '0');
        if (j >= 0) total += (b[j--] - '0');
        res[idx++] = (total % 2) + '0';
        carry = total / 2;
    }
    res[idx] = '\0';
    for (int k = 0; k < idx / 2; k++) {
        char t = res[k];
        res[k] = res[idx - 1 - k];
        res[idx - 1 - k] = t;
    }
    return res;
}