#include <stdio.h>

int rob(int *arr, int i, int n, int can_rob) {
    if(i >= n || arr[i] == -1) return 0;
    if(can_rob) {
        int rob_this = arr[i] + rob(arr, 2*i+1, n, 0) + rob(arr, 2*i+2, n, 0);
        int skip = rob(arr, 2*i+1, n, 1) + rob(arr, 2*i+2, n, 1);
        return rob_this > skip ? rob_this : skip;
    }
    return rob(arr, 2*i+1, n, 1) + rob(arr, 2*i+2, n, 1);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%d\n", rob(arr, 0, n, 1));
    return 0;
}
