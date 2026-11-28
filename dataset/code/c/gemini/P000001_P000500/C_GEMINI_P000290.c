#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int ns = strlen(s), np = strlen(p);
    *returnSize = 0;
    if (ns < np) return NULL;

    int* res = (int*)malloc(ns * sizeof(int));
    int pCount[26] = {0}, sCount[26] = {0};

    for (int i = 0; i < np; i++) pCount[p[i] - 'a']++;

    for (int i = 0; i < ns; i++) {
        sCount[s[i] - 'a']++;
        if (i >= np) sCount[s[i - np] - 'a']--;

        bool match = true;
        for (int k = 0; k < 26; k++) {
            if (pCount[k] != sCount[k]) { match = false; break; }
        }
        if (match) res[(*returnSize)++] = i - np + 1;
    }
    return res;
}