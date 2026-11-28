#include <ctype.h>

int countConsonants(char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
                count++;
            }
        }
    }
    return count;
}