#include <stdio.h>
int main() {
    for (char c = 'Z'; c >= 'A'; c--) {
        if (c < 'Z') printf(" ");
        printf("%c", c);
    }
    printf("\n");
    return 0;
}