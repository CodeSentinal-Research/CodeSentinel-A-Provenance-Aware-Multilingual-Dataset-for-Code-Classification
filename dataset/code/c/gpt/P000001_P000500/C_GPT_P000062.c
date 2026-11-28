#include <stdio.h>

int fact(int d) { int f = 1; for (int i = 2; i <= d; i++) f *= i; return f; }

int main(void) {
    int n, original, sum = 0;
    if (scanf("%d", &n) != 1) return 1;
    original = n;
    while (n > 0) { sum += fact(n % 10); n /= 10; }
    printf("%s\n", sum == original ? "Strong" : "Not Strong");
    return 0;
}
