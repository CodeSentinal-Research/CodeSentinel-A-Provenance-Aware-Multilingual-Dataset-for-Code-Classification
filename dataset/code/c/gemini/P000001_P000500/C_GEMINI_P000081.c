#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    if (scanf(" %c", &c) == 1) printf("%s\n", isdigit(c) ? "Digit" : "Not Digit");
    return 0;
}