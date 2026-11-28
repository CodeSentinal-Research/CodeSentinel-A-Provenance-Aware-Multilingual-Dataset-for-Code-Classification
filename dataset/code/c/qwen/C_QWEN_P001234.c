#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n], dep[n];
    for(int i=0; i<n; i++) scanf("%d%d", &arr[i], &dep[i]);
    qsort(arr, n, sizeof(int), cmp);
    qsort(dep, n, sizeof(int), cmp);
    int plat=1, max_plat=1, i=1, j=0;
    while(i<n && j<n) {
        if(arr[i] <= dep[j]) { plat++; i++; if(plat>max_plat) max_plat=plat; }
        else { plat--; j++; }
    }
    printf("%d\n", max_plat);
    return 0;
}
