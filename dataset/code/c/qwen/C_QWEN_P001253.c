#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int min_diff = a[1] - a[0];
    for(int i=2; i<n; i++) if(a[i]-a[i-1] < min_diff) min_diff = a[i]-a[i-1];
    int first = 1;
    for(int i=0; i<n-1; i++) {
        if(a[i+1]-a[i] == min_diff) { if(!first) printf(" "); printf("%d %d", a[i], a[i+1]); first=0; }
    }
    printf("\n");
    return 0;
}
