#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(double*)a > *(double*)b ? 1 : -1; }
int main() {
    int n; scanf("%d", &n);
    int dist[n], speed[n];
    for(int i=0; i<n; i++) scanf("%d", &dist[i]);
    for(int i=0; i<n; i++) scanf("%d", &speed[i]);
    double time[n];
    for(int i=0; i<n; i++) time[i] = (double)dist[i] / speed[i];
    qsort(time, n, sizeof(double), cmp);
    int count = 0;
    for(int i=0; i<n; i++) {
        if(time[i] > i) count++;
        else break;
    }
    printf("%d\n", count);
    return 0;
}
