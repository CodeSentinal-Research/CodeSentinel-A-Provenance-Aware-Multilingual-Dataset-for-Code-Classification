#include <stdlib.h>
#include <string.h>

char* frequencySort(char* s) {
    int count[256] = {0};
    for (int i = 0; s[i]; i++) count[(unsigned char)s[i]]++;

    int len = strlen(s);
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;

    while (idx < len) {
        int maxFreq = 0, bestChar = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > maxFreq) {
                maxFreq = count[i];
                bestChar = i;
            }
        }
        for (int i = 0; i < maxFreq; i++) {
            res[idx++] = (char)bestChar;
        }
        count[bestChar] = 0;
    }
    res[len] = '\0';
    return res;
}