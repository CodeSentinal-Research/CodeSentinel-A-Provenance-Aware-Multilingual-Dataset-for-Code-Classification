#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    if (ch >= 'A' && ch <= 'Z') ch = (char)(ch + 32); printf("%c\n", ch);
    return 0;
}
