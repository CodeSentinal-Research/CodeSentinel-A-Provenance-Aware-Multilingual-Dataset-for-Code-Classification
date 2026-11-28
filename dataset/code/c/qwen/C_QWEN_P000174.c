#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int min_diff = arr[1] - arr[0];
    for(int i=2; i<n; i++) if(arr[i]-arr[i-1] < min_diff) min_diff = arr[i]-arr[i-1];
    printf("%d\n", min_diff);
    return 0;
}
