#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n <= 1) { printf("Not Perfect\n"); return 0; }
        int sum = 0;
        for (int i = 1; i < n; i++) if (n % i == 0) sum += i;
        printf("%s\n", sum == n ? "Perfect" : "Not Perfect");
    }
    return 0;
}