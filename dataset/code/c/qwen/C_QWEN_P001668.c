#include <stdio.h>

int height(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    int l = height(arr, 2*i+1, n);
    int r = height(arr, 2*i+2, n);
    return 1 + (l > r ? l : r);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int h = height(arr, 0, n);
    int node = 0;
    for(int i=1; i<n; i++) {
        int hi = height(arr, i, n);
        if(hi == h) { node = i; break; }
    }
    printf("%d\n", arr[node]);
    return 0;
}
