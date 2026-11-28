#include <stdio.h>

int main() {
    char c;
    scanf(" %c", &c);
    printf("%s\n", (c >= 'A' && c <= 'Z') ? "Uppercase" : "Lowercase");
    return 0;
}
