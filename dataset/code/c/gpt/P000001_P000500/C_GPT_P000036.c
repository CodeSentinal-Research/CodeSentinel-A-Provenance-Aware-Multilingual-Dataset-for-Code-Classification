#include <stdio.h>

int main(void) {
    int n, bits[32], count = 0;
    if (scanf("%d", &n) != 1) return 1;
    if (n == 0) { printf("0\n"); return 0; }
    while (n > 0) { bits[count++] = n % 2; n /= 2; }
    for (int i = count - 1; i >= 0; i--) printf("%d", bits[i]);
    printf("\n");
    return 0;
}
