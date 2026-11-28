#include <stdlib.h>

char* printAlphabetZA() {
    char* res = (char*)malloc(27 * sizeof(char));
    for (int i = 0; i < 26; i++) {
        res[i] = 'Z' - i;
    }
    res[26] = '\0';
    return res;
}
