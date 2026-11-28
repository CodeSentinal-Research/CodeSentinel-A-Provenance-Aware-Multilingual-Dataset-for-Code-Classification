#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, coins; scanf("%d%d", &n, &coins);
    int cost[n]; for(int i=0; i<n; i++) scanf("%d", &cost[i]);
    qsort(cost, n, sizeof(int), cmp);
    int count = 0;
    for(int i=0; i<n; i++) {
        if(coins >= cost[i]) { coins -= cost[i]; count++; }
        else break;
    }
    printf("%d\n", count);
    return 0;
}
