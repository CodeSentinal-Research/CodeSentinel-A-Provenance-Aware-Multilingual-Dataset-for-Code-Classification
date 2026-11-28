#include <stdio.h>

int main(void) {
    for (int i = 32; i <= 126; i++) {
        printf("%c%s", (char)i, (i == 126) ? "\n" : " ");
    }
    return 0;
}
