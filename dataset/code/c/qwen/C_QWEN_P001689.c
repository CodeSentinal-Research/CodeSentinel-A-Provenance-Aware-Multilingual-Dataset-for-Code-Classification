#include <stdio.h>

int cameras(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    return 1 + cameras(arr, 2*i+1, n) + cameras(arr, 2*i+2, n);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%d\n", cameras(arr, 0, n) / 3 + 1);
    return 0;
}
