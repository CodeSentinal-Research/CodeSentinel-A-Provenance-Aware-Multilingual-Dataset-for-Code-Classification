#include <stdlib.h>
#include <string.h>

char* printAlphabetAZ() {
    char* res = (char*)malloc(27 * sizeof(char));
    for (int i = 0; i < 26; i++) {
        res[i] = 'A' + i;
    }
    res[26] = '\0';
    return res;
}
