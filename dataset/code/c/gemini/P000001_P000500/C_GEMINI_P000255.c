#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* removeVowels(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        char lower = tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            res[idx++] = c;
        }
    }
    res[idx] = '\0';
    return res;
}