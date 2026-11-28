#include <stdio.h>

int main() {
    char c;
    scanf(" %c", &c);
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        printf("Not Special Symbol\n");
    else
        printf("Special Symbol\n");
    return 0;
}
