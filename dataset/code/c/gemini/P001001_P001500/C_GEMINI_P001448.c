#include <stdbool.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Sorts the input array into ordered sequence.
bool isAlienSorted(char** words, int wordsSize, char* order) {
    int orderMap[26];
    for (int i = 0; order[i]; i++) orderMap[order[i] - 'a'] = i;

    for (int i = 0; i < wordsSize - 1; i++) {
        char *w1 = words[i], *w2 = words[i + 1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int minLen = MIN(len1, len2);
        bool diff = false;

        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                if (orderMap[w1[j] - 'a'] > orderMap[w2[j] - 'a']) return false;
                diff = true;
                break;
            }
        }
        if (!diff && len1 > len2) return false;
    }
    return true;
}