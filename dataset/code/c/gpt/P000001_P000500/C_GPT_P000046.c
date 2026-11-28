#include <stdio.h>

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("%s\n", (b != 0 && a % b == 0) ? "Divisible" : "Not Divisible");
    return 0;
}
