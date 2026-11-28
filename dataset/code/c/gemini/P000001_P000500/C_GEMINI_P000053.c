#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    if (scanf(" %c", &c) == 1) printf("%c\n", toupper(c));
    return 0;
}