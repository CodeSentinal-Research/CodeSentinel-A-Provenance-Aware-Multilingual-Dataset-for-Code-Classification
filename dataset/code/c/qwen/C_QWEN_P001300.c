#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int people[n], boats[m];
    for(int i=0; i<n; i++) scanf("%d", &people[i]);
    for(int i=0; i<m; i++) scanf("%d", &boats[i]);
    qsort(people, n, sizeof(int), cmp);
    qsort(boats, m, sizeof(int), cmp);
    int p = 0, b = 0, count = 0;
    while(p < n && b < m) {
        if(people[p] <= boats[b]) { p++; b++; count++; }
        else b++;
    }
    printf("%d\n", p == n ? count : -1);
    return 0;
}
