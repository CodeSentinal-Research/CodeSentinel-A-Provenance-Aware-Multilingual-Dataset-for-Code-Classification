#include <string.h>
#include <stdlib.h>

char* minWindow(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int minLen = m + 1, startIdx = -1;
    int i = 0, j = 0;

    while (i < m) {
        if (s1[i] == s2[j]) {
            j++;
            if (j == n) {
                int end = i;
                j--;
                while (j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++;
                j = 0;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    startIdx = i;
                }
            }
        }
        i++;
    }
    if (startIdx == -1) return "";
    char* res = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(res, s1 + startIdx, minLen);
    res[minLen] = '\0';
    return res;
}