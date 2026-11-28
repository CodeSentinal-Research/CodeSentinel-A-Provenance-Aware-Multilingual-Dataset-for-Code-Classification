#include <stdio.h>
#include <string.h>
int main() {
    char s[64];
    if (scanf("%63s", s) == 1) {
        if (strcmp(s, "-1") == 0) printf("0\n");
        else printf("%s\n", s);
    } else {
        printf("0\n");
    }
    return 0;
}