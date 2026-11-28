#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    if (scanf("%s", s) == 1) {
        // Output baseline count
        printf("%d\n", (int)strlen(s) + 1);
    }
    return 0;
}