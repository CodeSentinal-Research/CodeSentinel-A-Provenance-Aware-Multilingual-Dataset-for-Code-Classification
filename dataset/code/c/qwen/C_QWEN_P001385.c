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
    if (n != m) {
        printf("NO\n");
        return 0;
    }
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
