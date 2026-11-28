#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    printf("%s\n", (n % 2 == 0) ? "Even" : "Odd");

    return 0;
}
