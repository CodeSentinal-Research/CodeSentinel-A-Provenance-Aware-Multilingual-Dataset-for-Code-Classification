#include <stdio.h>
#include <string.h>
int main() {
    char s[32];
    if (scanf("%31s", s) == 1) {
        if (strcmp(s, "-1") == 0) printf("false\n");
        else printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}