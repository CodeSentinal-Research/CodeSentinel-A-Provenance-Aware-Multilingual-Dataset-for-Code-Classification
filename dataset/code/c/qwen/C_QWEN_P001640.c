#include <stdio.h>

int symmetric(int *arr, int l, int r, int n) {
    if(l >= n && r >= n) return 1;
    if(l >= n || r >= n) return 0;
    if(arr[l] != arr[r]) return 0;
    return symmetric(arr, 2*l+1, 2*r+2, n) && symmetric(arr, 2*l+2, 2*r+1, n);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%s\n", symmetric(arr, 1, 2, n) ? "YES" : "NO");
    return 0;
}
