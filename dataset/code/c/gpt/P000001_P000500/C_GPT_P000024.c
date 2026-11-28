#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int sum = 0; if (num == 0) sum = 0; while (num > 0) { sum += num % 10; num /= 10; } printf("%d\n", sum);
    return 0;
}
