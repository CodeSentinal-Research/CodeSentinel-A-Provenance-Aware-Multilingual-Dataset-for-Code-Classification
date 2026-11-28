#include <ctype.h>
#include <stdbool.h>

int countWords(char* s) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isspace(s[i])) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}