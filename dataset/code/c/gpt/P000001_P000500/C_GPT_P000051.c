#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    if (ch >= 'A' && ch <= 'Z') printf("Uppercase\n"); else if (ch >= 'a' && ch <= 'z') printf("Lowercase\n"); else printf("Not Alphabet\n");
    return 0;
}
