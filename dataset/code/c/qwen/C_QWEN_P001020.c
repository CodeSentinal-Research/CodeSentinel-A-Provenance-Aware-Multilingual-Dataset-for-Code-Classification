#include <stdio.h>
#include <stdlib.h>
int main() {
    int k; scanf("%d", &k);
    int lists[500][1000], sizes[500];
    int total = 0;
    for(int i=0; i<k; i++) {
        scanf("%d", &sizes[i]);
        for(int j=0; j<sizes[i]; j++) scanf("%d", &lists[i][j]);
        total += sizes[i];
    }
    int all[total], idx = 0;
    for(int i=0; i<k; i++) for(int j=0; j<sizes[i]; j++) all[idx++] = lists[i][j];
    qsort(all, total, sizeof(int), cmp);
    printf("%d %d\n", all[0], all[total-1]);
    return 0;
}
