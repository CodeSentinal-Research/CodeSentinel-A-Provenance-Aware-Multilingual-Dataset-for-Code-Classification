#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int k; scanf("%d", &k);
    int all[100001], idx=0;
    for(int i=0; i<k; i++) {
        int m; scanf("%d", &m);
        for(int j=0; j<m; j++) scanf("%d", &all[idx++]);
    }
    qsort(all, idx, sizeof(int), cmp);
    for(int i=0; i<idx; i++) printf("%d%c", all[i], i==idx-1?'\n':' ');
    return 0;
}
