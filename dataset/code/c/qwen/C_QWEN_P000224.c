#include <stdio.h>
#include <stdlib.h>
struct Job { int id, dead, profit; };
int cmp(const void *x, const void *y) { return ((struct Job*)y)->profit - ((struct Job*)x)->profit; }
int main() {
    int n; scanf("%d", &n);
    struct Job j[n];
    int max_dead = 0;
    for(int i=0; i<n; i++) { scanf("%d %d %d", &j[i].id, &j[i].dead, &j[i].profit); if(j[i].dead > max_dead) max_dead = j[i].dead; }
    qsort(j, n, sizeof(struct Job), cmp);
    int slot[max_dead+1], count=0, profit=0;
    for(int i=0; i<=max_dead; i++) slot[i] = -1;
    for(int i=0; i<n; i++) {
        for(int t=j[i].dead; t>0; t--) {
            if(slot[t] == -1) { slot[t] = j[i].id; count++; profit += j[i].profit; break; }
        }
    }
    printf("%d %d\n", count, profit);
    return 0;
}
