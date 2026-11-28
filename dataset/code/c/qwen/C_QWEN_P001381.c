#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    int i = 0, j = 0, first = 1;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            if (!first) printf(" ");
            printf("%d", a[i]);
            first = 0;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("\n");
    return 0;
}
