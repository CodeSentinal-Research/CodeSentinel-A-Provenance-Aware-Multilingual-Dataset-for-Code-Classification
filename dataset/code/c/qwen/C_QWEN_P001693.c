#include <stdio.h>

int univalue(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    int l = univalue(arr, 2*i+1, n);
    int r = univalue(arr, 2*i+2, n);
    int res = 0;
    if(2*i+1 < n && arr[2*i+1] == arr[i]) res += l + 1;
    if(2*i+2 < n && arr[2*i+2] == arr[i]) res += r + 1;
    return res;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_u = 0;
    for(int i=0; i<n; i++) {
        int u = univalue(arr, i, n);
        if(u > max_u) max_u = u;
    }
    printf("%d\n", max_u);
    return 0;
}
