#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    if (scanf("%s", s) == 1) {
        printf("%d\n", (int)strlen(s));
    }
    return 0;
}