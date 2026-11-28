#include <stdio.h>
int main() {
    char s[64];
    if (scanf("%63s", s) == 1) printf("%s\n", s);
    return 0;
}