#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int vals[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &vals[i]);
        qsort(vals, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++) printf("%d%s", vals[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}