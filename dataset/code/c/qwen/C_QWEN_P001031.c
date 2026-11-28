#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int n, m; scanf("%d%d", &n, &m);
    int a[n+m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &a[n+i]);
    int total = n+m;
    qsort(a, total, sizeof(int), cmp);
    for(int i=total/2-1; i>=0; i--) {
        int largest = i, l = 2*i+1, r = 2*i+2;
        if(l < total && a[l] > a[largest]) largest = l;
        if(r < total && a[r] > a[largest]) largest = r;
        if(largest != i) { int t=a[i]; a[i]=a[largest]; a[largest]=t; }
    }
    for(int i=0; i<total; i++) printf("%d%c", a[i], i==total-1?'\n':' ');
    return 0;
}
