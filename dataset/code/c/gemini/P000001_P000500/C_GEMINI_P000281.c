#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen) return "";

    int need[128] = {0};
    for (int k = 0; k < tLen; k++) need[(unsigned char)t[k]]++;

    int missing = tLen;
    int start = 0, minLen = INT_MAX;
    int i = 0;

    for (int j = 0; j < sLen; j++) {
        if (need[(unsigned char)s[j]] > 0) missing--;
        need[(unsigned char)s[j]]--;

        if (missing == 0) {
            while (i < j && need[(unsigned char)s[i]] < 0) {
                need[(unsigned char)s[i]]++;
                i++;
            }
            if (j - i + 1 < minLen) {
                start = i;
                minLen = j - i + 1;
            }
            need[(unsigned char)s[i]]++;
            missing++;
            i++;
        }
    }

    if (minLen == INT_MAX) return "";
    char* res = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(res, s + start, minLen);
    res[minLen] = '\0';
    return res;
}