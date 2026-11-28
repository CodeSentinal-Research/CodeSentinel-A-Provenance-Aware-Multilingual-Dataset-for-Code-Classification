#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toggleCase(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) res[i] = tolower(s[i]);
        else if (islower(s[i])) res[i] = toupper(s[i]);
        else res[i] = s[i];
    }
    res[n] = '\0';
    return res;
}