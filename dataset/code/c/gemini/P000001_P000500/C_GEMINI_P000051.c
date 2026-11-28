#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    if (scanf(" %c", &c) == 1) printf("%s\n", isupper(c) ? "Uppercase" : "Lowercase");
    return 0;
}