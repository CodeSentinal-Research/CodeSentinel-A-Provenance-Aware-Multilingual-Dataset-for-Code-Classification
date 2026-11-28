#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int count = 0; if (num == 0) count = 1; while (num > 0) { if ((num % 10) % 2 == 0) count++; num /= 10; } printf("%d\n", count);
    return 0;
}
