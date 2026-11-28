#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int vals[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int k;
    if (scanf("%d", &k) == 1) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            int sz; scanf("%d", &sz);
            for (int j = 0; j < sz; j++) scanf("%d", &vals[cnt++]);
        }
        qsort(vals, cnt, sizeof(int), cmp);
        for (int i = 0; i < cnt; i++) printf("%d%s", vals[i], i == cnt - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}