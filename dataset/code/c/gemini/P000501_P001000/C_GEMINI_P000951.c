#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int* phi = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 0; i <= n; i++) phi[i] = i;
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        long long sum = 0;
        for (int i = 1; i <= n; i++) sum += phi[i];
        printf("%lld\n", sum);
        free(phi);
    }
    return 0;
}