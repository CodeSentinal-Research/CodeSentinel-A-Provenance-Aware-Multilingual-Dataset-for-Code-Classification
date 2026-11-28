#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int sorted_a[n]; for(int i=0; i<n; i++) sorted_a[i] = a[i];
    qsort(sorted_a, n, sizeof(int), cmp);
    int res[n];
    for(int i=0; i<n; i++) {
        int idx = 0;
        for(int j=0; j<n; j++) if(a[j] == sorted_a[i] && res[j] == 0) { idx = j; break; }
        // simplified
    }
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
