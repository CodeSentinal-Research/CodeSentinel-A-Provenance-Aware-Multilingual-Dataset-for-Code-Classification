#include <stdlib.h>

char** getAllAscii(int* returnSize) {
    *returnSize = 128;  // write through pointer
    char** list = (char**)malloc(128 * sizeof(char*));
    for (int i = 0; i < 128; i++) {
        list[i] = (char*)malloc(2 * sizeof(char));
        list[i][0] = (char)i;
        list[i][1] = '\0';
    }
    return list;
}
