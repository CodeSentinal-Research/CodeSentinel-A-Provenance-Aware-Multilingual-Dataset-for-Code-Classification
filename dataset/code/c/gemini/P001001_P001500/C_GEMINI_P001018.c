#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reorganizeString(char* s) {
    int n = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < n; i++) count[s[i] - 'a']++;

    int maxCount = 0, letter = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            letter = i;
        }
    }
    if (maxCount > (n + 1) / 2) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char* res = (char*)malloc((n + 1) * sizeof(char));
    res[n] = '\0';
    int idx = 0;
    while (count[letter] > 0) {
        res[idx] = 'a' + letter;
        idx += 2;
        count[letter]--;
    }
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            if (idx >= n) idx = 1;
            res[idx] = 'a' + i;
            idx += 2;
            count[i]--;
        }
    }
    return res;
}