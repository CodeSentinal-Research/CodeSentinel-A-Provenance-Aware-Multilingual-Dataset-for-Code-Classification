#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int product = (num == 0) ? 0 : 1; while (num > 0) { product *= num % 10; num /= 10; } printf("%d\n", product);
    return 0;
}
