#include <stdio.h>
#include <math.h>

double nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    double ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main() {
    int n, k;
    double p;
    if (scanf("%d %d %lf", &n, &k, &p) == 3) {
        double ans = nCr(n, k) * pow(p, k) * pow(1.0 - p, n - k);
        printf("%.6f\n", ans);
    }
    return 0;
}