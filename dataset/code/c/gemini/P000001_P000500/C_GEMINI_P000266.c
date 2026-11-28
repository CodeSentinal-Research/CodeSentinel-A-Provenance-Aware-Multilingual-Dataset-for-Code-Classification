#include <stdlib.h>
#include <string.h>

char* removeOccurrences(char* s, char c) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) res[idx++] = s[i];
    }
    res[idx] = '\0';
    return res;
}