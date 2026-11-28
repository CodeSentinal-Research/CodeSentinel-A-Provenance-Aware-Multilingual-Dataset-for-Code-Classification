#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int vals[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int cnt = 0;
    while (scanf("%d", &vals[cnt]) == 1) cnt++;
    if (cnt == 0) return 0;
    qsort(vals, cnt, sizeof(int), cmp);
    for (int i = 0; i < cnt; i++) {
        printf("%d%s", vals[i], i == cnt - 1 ? "" : " ");
    }
    printf("\n");
    return 0;
}