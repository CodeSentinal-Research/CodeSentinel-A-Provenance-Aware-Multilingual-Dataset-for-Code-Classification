#include <stdio.h>

void mirror(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return;
    int l = 2*i+1, r = 2*i+2;
    if(l < n && r < n) {
        int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
        mirror(arr, l, n); mirror(arr, r, n);
    } else if(l < n) {
        // simplified
    }
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    mirror(arr, 0, n);
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
