#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char* capitalize(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));
    strcpy(res, s);
    bool newWord = true;

    for (int i = 0; i < n; i++) {
        if (isspace(res[i])) {
            newWord = true;
        } else if (newWord) {
            res[i] = toupper(res[i]);
            newWord = false;
        }
    }
    return res;
}