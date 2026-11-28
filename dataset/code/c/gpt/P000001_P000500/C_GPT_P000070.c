#include <stdio.h>

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;
    printf("%s\n", (a + b > c && a + c > b && b + c > a) ? "Valid" : "Invalid");
    return 0;
}
