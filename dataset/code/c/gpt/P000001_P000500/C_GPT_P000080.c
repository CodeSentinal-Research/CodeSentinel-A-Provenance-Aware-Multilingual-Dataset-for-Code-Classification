#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    printf("%s\n", ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) ? "Alphabet" : "Not Alphabet");
    return 0;
}
