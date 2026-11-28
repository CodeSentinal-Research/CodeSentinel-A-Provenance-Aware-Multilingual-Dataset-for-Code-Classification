#include <stdio.h>
#include <stdlib.h>

int cmpMerge(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int* a = (int*)malloc(n * sizeof(int));
        int* b = (int*)malloc(m * sizeof(int));
        for (int k = 0; k < n; k++) scanf("%d", &a[k]);
        for (int k = 0; k < m; k++) scanf("%d", &b[k]);

        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                int tmp = a[i]; a[i] = b[j]; b[j] = tmp;
                i--; j++;
            } else {
                break;
            }
        }
        qsort(a, n, sizeof(int), cmpMerge);
        qsort(b, m, sizeof(int), cmpMerge);

        for (int k = 0; k < n; k++) printf("%d ", a[k]);
        for (int k = 0; k < m; k++) printf("%d%s", b[k], k + 1 == m ? "" : " ");
        printf("\n");
        free(a);
        free(b);
    }
    return 0;
}