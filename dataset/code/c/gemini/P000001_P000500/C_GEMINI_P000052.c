#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    if (scanf(" %c", &c) == 1) printf("%c\n", tolower(c));
    return 0;
}