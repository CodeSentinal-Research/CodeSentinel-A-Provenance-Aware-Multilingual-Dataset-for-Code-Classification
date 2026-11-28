#include <stdio.h>

int sumBinary(int *arr, int i, int n, int val) {
    if(i >= n || arr[i] == -1) return 0;
    val = val * 2 + arr[i];
    if(2*i+1 >= n && 2*i+2 >= n) return val;
    return sumBinary(arr, 2*i+1, n, val) + sumBinary(arr, 2*i+2, n, val);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%d\n", sumBinary(arr, 0, n, 0));
    return 0;
}
