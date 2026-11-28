#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int max_sum = 0;
    for(int i=0; i<n/2; i++) {
        if(arr[i] + arr[n-1-i] > max_sum) max_sum = arr[i] + arr[n-1-i];
    }
    printf("%d\n", max_sum);
    return 0;
}
