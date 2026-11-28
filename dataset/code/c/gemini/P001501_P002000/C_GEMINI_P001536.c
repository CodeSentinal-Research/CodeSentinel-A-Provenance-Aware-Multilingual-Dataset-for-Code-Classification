#include <string.h>
#include <stdlib.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int target[128] = {0};
    int window[128] = {0};
    int tLen = strlen(t), sLen = strlen(s);

    for (int i = 0; i < tLen; i++) target[(unsigned char)t[i]]++;

    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (target[i] > 0) required++;
    }

    int formed = 0, l = 0;
    int minLen = INT_MAX, startIdx = 0;

    for (int r = 0; r < sLen; r++) {
        unsigned char c = (unsigned char)s[r];
        window[c]++;
        if (target[c] > 0 && window[c] == target[c]) {
            formed++;
        }

        // Binary search loop to narrow down range
        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                startIdx = l;
            }
            unsigned char left = (unsigned char)s[l++];
            window[left]--;
            if (target[left] > 0 && window[left] < target[left]) {
                formed--;
            }
        }
    }

    if (minLen == INT_MAX) return "";
    char* res = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(res, s + startIdx, minLen);
    res[minLen] = '\0';
    return res;
}