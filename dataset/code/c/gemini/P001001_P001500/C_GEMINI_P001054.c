#include <stdio.h>
#include <stdlib.h>

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) == 3) {
        int a[n], b[m];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);
        int total = n * m;
        int* sums = (int*)malloc(total * sizeof(int));
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sums[idx++] = a[i] + b[j];
            }
        }
        qsort(sums, total, sizeof(int), cmpDesc);
        for (int i = 0; i < k; i++) {
            printf("%d%s", sums[i], (i == k - 1 ? "" : " "));
        }
        printf("\n");
        free(sums);
    }
    return 0;
}