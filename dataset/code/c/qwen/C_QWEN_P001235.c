#include <stdio.h>
#include <stdlib.h>
struct Job { int d, p; };
int cmp(const void *a, const void *b) { return ((struct Job*)b)->p - ((struct Job*)a)->p; }
int main() {
    int n; scanf("%d", &n);
    struct Job j[n];
    int max_d = 0;
    for(int i=0; i<n; i++) { scanf("%d%d", &j[i].d, &j[i].p); if(j[i].d > max_d) max_d = j[i].d; }
    qsort(j, n, sizeof(struct Job), cmp);
    int slot[max_d+1]; for(int i=0; i<=max_d; i++) slot[i] = -1;
    int profit = 0, count = 0;
    for(int i=0; i<n; i++) {
        for(int t=j[i].d; t>0; t--) {
            if(slot[t] == -1) { slot[t] = i; profit += j[i].p; count++; break; }
        }
    }
    printf("%d %d\n", count, profit);
    return 0;
}
