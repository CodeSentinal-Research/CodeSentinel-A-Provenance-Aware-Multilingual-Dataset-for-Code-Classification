#include <stdio.h>

int foldable(int *arr, int l, int r, int n) {
    if(l >= n && r >= n) return 1;
    if(l >= n || r >= n) return 0;
    return foldable(arr, 2*l+1, 2*r+2, n) && foldable(arr, 2*l+2, 2*r+1, n);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%s\n", foldable(arr, 1, 2, n) ? "YES" : "NO");
    return 0;
}
