#include <stdio.h>

int main() {
    char c;
    scanf(" %c", &c);
    printf("%s\n", (c >= '0' && c <= '9') ? "Digit" : "Not Digit");
    return 0;
}
