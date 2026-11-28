#include <stdio.h>
#include <stdlib.h>

int n;
int a[10], cur[10], used[10];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void gen(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) printf("%d ", cur[j]);
        printf("\n");
        return;
    }
    for (int j = 0; j < n; j++) {
        if (used[j] || (j > 0 && a[j] == a[j - 1] && !used[j - 1])) continue;
        used[j] = 1;
        cur[i] = a[j];
        gen(i + 1);
        used[j] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    gen(0);
    return 0;
}
