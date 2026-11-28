#include <stdio.h>
#include <string.h>

int main() {
    char s[1005], t[1005];
    if (scanf("%1004s %1004s", s, t) == 2) {
        char res = 0;
        for (int i = 0; s[i]; i++) res ^= s[i];
        for (int i = 0; t[i]; i++) res ^= t[i];
        printf("%c\n", res);
    }
    return 0;
}