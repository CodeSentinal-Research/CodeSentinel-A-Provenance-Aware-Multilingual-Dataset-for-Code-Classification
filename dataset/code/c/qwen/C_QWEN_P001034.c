#include <stdio.h>
#include <stdlib.h>
int main() {
    int k; scanf("%d", &k);
    int total = 0;
    int lists[1000][1000], sizes[1000];
    for(int i=0; i<k; i++) {
        scanf("%d", &sizes[i]);
        for(int j=0; j<sizes[i]; j++) scanf("%d", &lists[i][j]);
        total += sizes[i];
    }
    int all[total], idx = 0;
    for(int i=0; i<k; i++) for(int j=0; j<sizes[i]; j++) all[idx++] = lists[i][j];
    qsort(all, total, sizeof(int), cmp);
    for(int i=0; i<total; i++) printf("%d%c", all[i], i==total-1?'\n':' ');
    return 0;
}
