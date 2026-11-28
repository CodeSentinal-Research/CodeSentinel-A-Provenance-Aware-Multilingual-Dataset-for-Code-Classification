#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool detectCapitalUse(const char* word) {
    int caps = 0, len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) caps++;
    }
    return caps == len || caps == 0 || (caps == 1 && isupper(word[0]));
}

int main() {
    char word[105];
    if (scanf("%104s", word) == 1) {
        printf("%s\n", detectCapitalUse(word) ? "Yes" : "No");
    }
    return 0;
}