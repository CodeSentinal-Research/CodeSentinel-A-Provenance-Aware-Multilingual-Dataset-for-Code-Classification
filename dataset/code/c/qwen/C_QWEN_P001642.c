#include <stdio.h>

int height(int *arr, int i, int n, int *max_d) {
    if(i >= n || arr[i] == -1) return 0;
    int l = height(arr, 2*i+1, n, max_d);
    int r = height(arr, 2*i+2, n, max_d);
    if(l + r > *max_d) *max_d = l + r;
    return 1 + (l > r ? l : r);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_d = 0;
    height(arr, 0, n, &max_d);
    printf("%d\n", max_d);
    return 0;
}
