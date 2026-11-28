#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, rocks; scanf("%d%d", &n, &rocks);
    int cap[n], cur[n];
    for(int i=0; i<n; i++) scanf("%d", &cap[i]);
    for(int i=0; i<n; i++) scanf("%d", &cur[i]);
    int diff[n]; for(int i=0; i<n; i++) diff[i] = cap[i] - cur[i];
    qsort(diff, n, sizeof(int), cmp);
    int count = 0;
    for(int i=0; i<n; i++) {
        if(rocks >= diff[i]) { rocks -= diff[i]; count++; }
        else break;
    }
    printf("%d\n", count);
    return 0;
}
