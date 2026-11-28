#include <stdio.h>

int main(void) {
    char ch;

    if (scanf(" %c", &ch) != 1) {
        return 1;
    }

    printf("%d\n", (int)ch);

    return 0;
}
