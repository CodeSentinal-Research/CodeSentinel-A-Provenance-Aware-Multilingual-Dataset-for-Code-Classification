#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    if (scanf("%999s", s) == 1) {
        int len = strlen(s);
        for (int i = len - 1; i >= 0; i--) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}