#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n], sorted[n];
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); sorted[i] = a[i]; }
    qsort(sorted, n, sizeof(int), cmp);
    int chunks = 0, max_a = 0, max_s = 0;
    for(int i=0; i<n; i++) {
        if(a[i] > max_a) max_a = a[i];
        if(sorted[i] > max_s) max_s = sorted[i];
        if(max_a == max_s) chunks++;
    }
    printf("%d\n", chunks);
    return 0;
}
