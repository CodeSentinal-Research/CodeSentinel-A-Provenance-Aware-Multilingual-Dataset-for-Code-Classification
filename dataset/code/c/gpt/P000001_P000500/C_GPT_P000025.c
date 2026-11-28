#include <stdio.h>

int main(void) {
    int num, original, reversed = 0;
    if (scanf("%d", &num) != 1) return 1;
    original = num;
    while (num != 0) { reversed = reversed * 10 + num % 10; num /= 10; }
    printf("%d\n", reversed);
    return 0;
}
