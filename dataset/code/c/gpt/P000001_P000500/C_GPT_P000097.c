#include <stdio.h>

int main(void) {
    int num;
    if (scanf("%d", &num) != 1) return 1;
    int has_zero = 0; while (num > 0) { if (num % 10 == 0) has_zero = 1; num /= 10; } printf("%s\n", has_zero ? "Duck" : "Not Duck");
    return 0;
}
