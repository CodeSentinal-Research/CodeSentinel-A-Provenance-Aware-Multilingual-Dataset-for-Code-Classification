#include <stdio.h>
#include <stdlib.h>

int height(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    int l = height(arr, 2*i+1, n);
    int r = height(arr, 2*i+2, n);
    if(l == -1 || r == -1 || abs(l-r) > 1) return -1;
    return 1 + (l > r ? l : r);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%s\n", height(arr, 0, n) != -1 ? "YES" : "NO");
    return 0;
}
