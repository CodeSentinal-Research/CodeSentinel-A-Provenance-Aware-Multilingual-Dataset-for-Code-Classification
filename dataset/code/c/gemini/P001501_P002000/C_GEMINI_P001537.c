#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s), pLen = strlen(p);
    *returnSize = 0;
    if (sLen < pLen) return NULL;

    int* res = (int*)malloc(sLen * sizeof(int));
    int pCount[26] = {0}, sCount[26] = {0};
    for (int i = 0; i < pLen; i++) pCount[p[i] - 'a']++;

    int count = 0;
    for (int i = 0; i < sLen; i++) {
        sCount[s[i] - 'a']++;
        if (i >= pLen) {
            sCount[s[i - pLen] - 'a']--;
        }
        bool match = true;
        for (int j = 0; j < 26; j++) {
            if (pCount[j] != sCount[j]) { match = false; break; }
        }
        if (match) res[count++] = i - pLen + 1;
    }

    *returnSize = count;
    return res;
}