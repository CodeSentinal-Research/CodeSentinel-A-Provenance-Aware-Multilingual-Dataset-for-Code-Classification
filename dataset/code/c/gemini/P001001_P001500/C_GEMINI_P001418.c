#include <stdbool.h>

int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    bool allow[26] = {false};
    for (int i = 0; allowed[i]; i++) allow[allowed[i] - 'a'] = true;

    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        bool consistent = true;
        for (int j = 0; words[i][j]; j++) {
            if (!allow[words[i][j] - 'a']) {
                consistent = false;
                break;
            }
        }
        if (consistent) count++;
    }
    return count;
}