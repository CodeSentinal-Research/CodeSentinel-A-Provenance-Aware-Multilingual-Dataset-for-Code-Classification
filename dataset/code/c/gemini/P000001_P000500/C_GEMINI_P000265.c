#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int seen[256] = {0};
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (!seen[(unsigned char)s[i]]) {
            seen[(unsigned char)s[i]] = 1;
            res[idx++] = s[i];
        }
    }
    res[idx] = '\0';
    return res;
}