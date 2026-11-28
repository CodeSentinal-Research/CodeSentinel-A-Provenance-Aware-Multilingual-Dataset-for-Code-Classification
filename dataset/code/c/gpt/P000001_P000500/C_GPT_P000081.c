#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    printf("%s\n", (ch >= '0' && ch <= '9') ? "Digit" : "Not Digit");
    return 0;
}
