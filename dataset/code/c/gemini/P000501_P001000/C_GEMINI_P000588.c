#include <stdio.h>
int main() {
    char s[128];
    int first = 1;
    while (scanf("%127s", s) == 1) {
        if (!first) printf(" ");
        printf("%s", s);
        first = 0;
    }
    printf("\n");
    return 0;
}