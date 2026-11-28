#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool matchCamel(char* q, char* pattern) {
    int j = 0, pLen = strlen(pattern);
    for (int i = 0; q[i]; i++) {
        if (j < pLen && q[i] == pattern[j]) {
            j++;
        } else if (q[i] >= 'A' && q[i] <= 'Z') {
            return false;
        }
    }
    return j == pLen;
}

bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    bool* res = (bool*)malloc(queriesSize * sizeof(bool));
    for (int i = 0; i < queriesSize; i++) {
        res[i] = matchCamel(queries[i], pattern);
    }
    *returnSize = queriesSize;
    return res;
}