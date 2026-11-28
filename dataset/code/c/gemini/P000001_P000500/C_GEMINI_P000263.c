#include <string.h>

char lastNonRepeatingCharacter(char* s) {
    int freq[256] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) freq[(unsigned char)s[i]]++;
    for (int i = n - 1; i >= 0; i--) {
        if (freq[(unsigned char)s[i]] == 1) return s[i];
    }
    return '$';
}