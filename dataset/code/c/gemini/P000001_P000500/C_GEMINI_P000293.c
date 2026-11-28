#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* encodeCodec(char** strs, int strsSize) {
    char* res = (char*)malloc(100005 * sizeof(char));
    res[0] = '\0';
    char buf[32];
    for (int i = 0; i < strsSize; i++) {
        sprintf(buf, "%lu#", strlen(strs[i]));
        strcat(res, buf);
        strcat(res, strs[i]);
    }
    return res;
}