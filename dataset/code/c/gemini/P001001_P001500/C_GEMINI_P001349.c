#include <stdlib.h>
#include <string.h>

char* smallestNumber(char* pattern) {
    int n = strlen(pattern);
    char* res = (char*)malloc((n + 2) * sizeof(char));
    int stack[n + 2];
    int top = 0, idx = 0;

    for (int i = 0; i <= n; i++) {
        stack[top++] = i + 1;
        if (i == n || pattern[i] == 'I') {
            while (top > 0) {
                res[idx++] = '0' + stack[--top];
            }
        }
    }
    res[idx] = '\0';
    return res;
}