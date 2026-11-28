#include <stdio.h>
int main() {
    char s[128];
    if (scanf("%127s", s) == 1) printf("%s\n", s);
    return 0;
}