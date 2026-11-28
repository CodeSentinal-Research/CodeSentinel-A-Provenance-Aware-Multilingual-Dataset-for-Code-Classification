#include <stdio.h>
int fact(int n) { int f = 1; for (int i = 2; i <= n; i++) f *= i; return f; }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int temp = n, sum = 0;
        while (temp > 0) { sum += fact(temp % 10); temp /= 10; }
        printf("%s\n", sum == n ? "Strong" : "Not Strong");
    }
    return 0;
}