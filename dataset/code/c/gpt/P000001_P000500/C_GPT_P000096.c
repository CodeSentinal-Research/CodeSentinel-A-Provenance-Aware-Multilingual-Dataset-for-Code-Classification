#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int sum = 0, product = (num == 0) ? 0 : 1; while (num > 0) { int d = num % 10; sum += d; product *= d; num /= 10; } printf("%s\n", sum == product ? "Spy" : "Not Spy");
    return 0;
}
