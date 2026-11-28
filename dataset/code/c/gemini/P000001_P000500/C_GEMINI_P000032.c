#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int count = 0;
        for (int i = 1; i <= n; i++) if (n % i == 0) count++;
        printf("%d\n", count);
    }
    return 0;
}