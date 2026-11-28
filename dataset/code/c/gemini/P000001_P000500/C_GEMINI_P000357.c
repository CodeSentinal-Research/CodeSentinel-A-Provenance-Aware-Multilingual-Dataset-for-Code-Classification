#include <stdio.h>
#include <string.h>

int main() {
    char s[100005], c;
    if (scanf("%100000s %c", s, &c) == 2) {
        int count = 0;
        for (int i = 0; s[i]; i++) if (s[i] == c) count++;
        printf("%d\n", count);
    }
    return 0;
}