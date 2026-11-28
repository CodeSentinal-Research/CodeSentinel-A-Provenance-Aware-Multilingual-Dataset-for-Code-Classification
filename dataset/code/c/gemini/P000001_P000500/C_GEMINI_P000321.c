#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getRow(char c) {
    c = tolower(c);
    const char* r1 = "qwertyuiop";
    const char* r2 = "asdfghjkl";
    const char* r3 = "zxcvbnm";
    if (strchr(r1, c)) return 1;
    if (strchr(r2, c)) return 2;
    if (strchr(r3, c)) return 4;
    return 0;
}

int main() {
    char word[105];
    while (scanf("%104s", word) == 1) {
        int mask = 0;
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            mask |= getRow(word[i]);
        }
        if (mask == 1 || mask == 2 || mask == 4) {
            printf("%s\n", word);
        }
    }
    return 0;
}