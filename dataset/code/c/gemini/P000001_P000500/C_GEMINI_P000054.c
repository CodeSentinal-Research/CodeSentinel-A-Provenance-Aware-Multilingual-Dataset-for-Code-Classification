#include <stdio.h>
int main() {
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c > 'A') printf(" ");
        printf("%c", c);
    }
    printf("\n");
    return 0;
}