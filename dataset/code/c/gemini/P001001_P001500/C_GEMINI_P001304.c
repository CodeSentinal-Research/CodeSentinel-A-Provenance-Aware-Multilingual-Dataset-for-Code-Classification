#include <stdio.h>
#include <stdlib.h>

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int* x = (int*)malloc((m - 1) * sizeof(int));
        for (int i = 0; i < m - 1; i++) scanf("%d", &x[i]);
        int* y = (int*)malloc((n - 1) * sizeof(int));
        for (int j = 0; j < n - 1; j++) scanf("%d", &y[j]);

        qsort(x, m - 1, sizeof(int), cmpDesc);
        qsort(y, n - 1, sizeof(int), cmpDesc);

        long long hPieces = 1, vPieces = 1, totalCost = 0;
        int i = 0, j = 0;

        while (i < m - 1 && j < n - 1) {
            if (x[i] >= y[j]) {
                totalCost += (long long)x[i] * vPieces;
                hPieces++;
                i++;
            } else {
                totalCost += (long long)y[j] * hPieces;
                vPieces++;
                j++;
            }
        }
        while (i < m - 1) {
            totalCost += (long long)x[i] * vPieces;
            i++;
        }
        while (j < n - 1) {
            totalCost += (long long)y[j] * hPieces;
            j++;
        }

        printf("%lld\n", totalCost);
        free(x);
        free(y);
    }
    return 0;
}