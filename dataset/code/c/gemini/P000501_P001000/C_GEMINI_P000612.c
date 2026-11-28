#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
// Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        for (int i = 0; i < n; i++) {
            printf("%d ", vals[i]);
            if (i + 1 < n) printf("%d%s", gcd(vals[i], vals[i + 1]), i + 1 == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}