#include <stdbool.h>
#include <string.h>

void buildStr(char* in, char* out) {
    int idx = 0;
    for (int i = 0; in[i]; i++) {
        if (in[i] != '#') {
            out[idx++] = in[i];
        } else if (idx > 0) {
            idx--;
        }
    }
    out[idx] = '\0';
}

bool backspaceCompare(char* s, char* t) {
    char sOut[205], tOut[205];
    buildStr(s, sOut);
    buildStr(t, tOut);
    return strcmp(sOut, tOut) == 0;
}