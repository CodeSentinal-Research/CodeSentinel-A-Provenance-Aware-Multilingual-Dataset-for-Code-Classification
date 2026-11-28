#include <stdio.h>
#include <stdlib.h>

int maxDiff(int *arr, int i, int n, int min_val, int max_val) {
    if(i >= n || arr[i] == -1) return max_val - min_val;
    if(arr[i] < min_val) min_val = arr[i];
    if(arr[i] > max_val) max_val = arr[i];
    int l = maxDiff(arr, 2*i+1, n, min_val, max_val);
    int r = maxDiff(arr, 2*i+2, n, min_val, max_val);
    return l > r ? l : r;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%d\n", maxDiff(arr, 0, n, arr[0], arr[0]));
    return 0;
}
