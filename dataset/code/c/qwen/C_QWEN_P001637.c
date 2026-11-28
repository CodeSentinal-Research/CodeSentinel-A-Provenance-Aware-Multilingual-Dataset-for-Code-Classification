#include <stdio.h>

int countLeaves(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    int l = 2*i+1, r = 2*i+2;
    if((l >= n || arr[l] == -1) && (r >= n || arr[r] == -1)) return 1;
    return countLeaves(arr, l, n) + countLeaves(arr, r, n);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%d\n", countLeaves(arr, 0, n));
    return 0;
}
