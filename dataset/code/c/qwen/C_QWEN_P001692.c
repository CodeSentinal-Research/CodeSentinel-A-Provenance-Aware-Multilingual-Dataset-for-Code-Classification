#include <stdio.h>

int consec(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    int l = 0, r = 0;
    if(2*i+1 < n && arr[2*i+1] != -1 && arr[2*i+1] == arr[i] + 1) l = 1 + consec(arr, 2*i+1, n);
    if(2*i+2 < n && arr[2*i+2] != -1 && arr[2*i+2] == arr[i] + 1) r = 1 + consec(arr, 2*i+2, n);
    return l > r ? l : r;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_c = 0;
    for(int i=0; i<n; i++) {
        int c = consec(arr, i, n);
        if(c > max_c) max_c = c;
    }
    printf("%d\n", max_c);
    return 0;
}
