#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

char** commonChars(char** words, int wordsSize, int* returnSize) {
    int common[26];
    for (int i = 0; i < 26; i++) common[i] = 10000;

    for (int i = 0; i < wordsSize; i++) {
        int count[26] = {0};
        for (int j = 0; words[i][j]; j++) count[words[i][j] - 'a']++;
        for (int j = 0; j < 26; j++) common[j] = MIN(common[j], count[j]);
    }

    int total = 0;
    for (int i = 0; i < 26; i++) total += common[i];

    char** res = (char**)malloc(total * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < 26; i++) {
        while (common[i]-- > 0) {
            res[idx] = (char*)malloc(2 * sizeof(char));
            res[idx][0] = 'a' + i;
            res[idx][1] = '\0';
            idx++;
        }
    }
    *returnSize = total;
    return res;
}