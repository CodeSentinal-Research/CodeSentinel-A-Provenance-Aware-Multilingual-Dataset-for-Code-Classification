#include <stdio.h>
#include <limits.h>

int isBST(int *arr, int i, int n, int min, int max) {
    if(i >= n || arr[i] == -1) return 1;
    if(arr[i] <= min || arr[i] >= max) return 0;
    return isBST(arr, 2*i+1, n, min, arr[i]) && isBST(arr, 2*i+2, n, arr[i], max);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%s\n", isBST(arr, 0, n, INT_MIN, INT_MAX) ? "YES" : "NO");
    return 0;
}
