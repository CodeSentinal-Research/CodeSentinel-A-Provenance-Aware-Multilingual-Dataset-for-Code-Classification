#include <string.h>
#include <stdlib.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        while (k > 0 && top > 0 && stack[top - 1] > num[i]) {
            top--;
            k--;
        }
        stack[top++] = num[i];
    }
    top -= k;

    int start = 0;
    while (start < top && stack[start] == '0') start++;

    if (start == top) {
        free(stack);
        return "0";
    }

    char* res = (char*)malloc((top - start + 1) * sizeof(char));
    strncpy(res, stack + start, top - start);
    res[top - start] = '\0';
    free(stack);
    return res;
}