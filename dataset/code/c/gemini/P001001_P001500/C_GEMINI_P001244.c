#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reorganizeString(char* s) {
    int n = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < n; i++) count[s[i] - 'a']++;

    int maxCount = 0, maxLetter = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxLetter = i;
        }
    }
    if (maxCount > (n + 1) / 2) return "";

    char* res = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    while (count[maxLetter] > 0) {
        res[idx] = 'a' + maxLetter;
        idx += 2;
        count[maxLetter]--;
    }

    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (idx >= n) idx = 1;
            res[idx] = 'a' + i;
            idx += 2;
            count[i]--;
        }
    }
    res[n] = '\0';
    return res;
}