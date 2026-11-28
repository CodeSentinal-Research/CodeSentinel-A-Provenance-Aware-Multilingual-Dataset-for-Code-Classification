#include <string.h>
#include <stdbool.h>

bool isSubseq(char* s, char* w) {
    int i = 0, j = 0;
    while (s[i] && w[j]) {
        if (s[i] == w[j]) j++;
        i++;
    }
    return w[j] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* best = "";
    for (int i = 0; i < dictionarySize; i++) {
        char* w = dictionary[i];
        if (isSubseq(s, w)) {
            int lenW = strlen(w), lenB = strlen(best);
            if (lenW > lenB || (lenW == lenB && strcmp(w, best) < 0)) {
                best = w;
            }
        }
    }
    return best;
}