#include <stdio.h>

int main(void) {
    int num, count = 0;
    if (scanf("%d", &num) != 1) return 1;
    if (num == 0) count = 1;
    while (num > 0) { count++; num /= 10; }
    printf("%d\n", count);
    return 0;
}
