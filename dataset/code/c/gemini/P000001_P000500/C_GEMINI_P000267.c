#include <stdlib.h>
#include <string.h>

char* replaceChar(char* s, char c1, char c2) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        res[i] = (s[i] == c1 ? c2 : s[i]);
    }
    res[n] = '\0';
    return res;
}