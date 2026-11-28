#include <stdio.h>
#include <stdlib.h>

int n;
int a[20], cur[20];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void gen(int i, int j) {
    if (i == n) {
        printf("[");
        for (int x = 0; x < j; x++) printf("%d ", cur[x]);
        printf("]\n");
        return;
    }
    cur[j] = a[i];
    gen(i + 1, j + 1);
    while (i + 1 < n && a[i] == a[i + 1]) i++;
    gen(i + 1, j);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    gen(0, 0);
    return 0;
}
