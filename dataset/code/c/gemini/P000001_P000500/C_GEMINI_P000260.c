#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* to_lower(char* str) {
    int n = strlen(str);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        res[i] = tolower(str[i]);
    }
    res[n] = '\0';
    return res;
}