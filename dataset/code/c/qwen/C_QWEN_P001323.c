#include <stdio.h>
#include <stdlib.h>

int n, t;
int a[100], cur[100];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void gen(int i, int sum) {
    if (sum == t) {
        for (int j = 0; j < i; j++) printf("%d ", cur[j]);
        printf("\n");
        return;
    }
    for (int k = i; k < n; k++) {
        if (k > i && a[k] == a[k - 1]) continue;
        if (sum + a[k] > t) break;
        cur[i] = a[k];
        gen(k + 1, sum + a[k]);
    }
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    gen(0, 0);
    return 0;
}
