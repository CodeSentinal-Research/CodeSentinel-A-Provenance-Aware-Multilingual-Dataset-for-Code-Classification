#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int max_freq = 0, l = 0;
    long long ops = 0;
    for(int r=0; r<n; r++) {
        ops += (long long)(arr[r] - arr[l]) * (r - l); // simplified logic
        while(ops > k) { ops -= arr[r] - arr[l]; l++; }
        if(r - l + 1 > max_freq) max_freq = r - l + 1;
    }
    printf("%d\n", max_freq);
    return 0;
}
