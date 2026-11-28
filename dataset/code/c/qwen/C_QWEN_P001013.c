#include <stdio.h>
#include <stdlib.h>
int cmp_max(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int cmp_min(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int max_h[n], min_h[n], max_sz=0, min_sz=0;
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        max_h[max_sz++] = x; qsort(max_h, max_sz, sizeof(int), cmp_max);
        min_h[min_sz++] = x; qsort(min_h, min_sz, sizeof(int), cmp_min);
        if(max_sz > min_sz) { int t=max_h[0]; max_h[0]=min_h[0]; min_h[0]=t; }
        if(i%2==0) printf("%.1f\n", (double)min_h[0]);
        else printf("%.1f\n", (min_h[0]+max_h[0])/2.0);
    }
    return 0;
}
