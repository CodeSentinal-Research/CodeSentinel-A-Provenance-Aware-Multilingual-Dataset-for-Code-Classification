#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int deck[MAX_N], res[MAX_N], q[MAX_N * 2];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &deck[i]);
        qsort(deck, n, sizeof(int), cmp);
        int head = 0, tail = 0;
        for (int i = 0; i < n; i++) q[tail++] = i;
        for (int i = 0; i < n; i++) {
            res[q[head++]] = deck[i];
            if (head < tail) {
                q[tail++] = q[head++];
            }
        }
        for (int i = 0; i < n; i++) printf("%d%s", res[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}