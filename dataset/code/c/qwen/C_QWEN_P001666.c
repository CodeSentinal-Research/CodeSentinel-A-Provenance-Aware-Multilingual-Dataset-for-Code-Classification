#include <stdio.h>

int zigzag(int *arr, int i, int n, int dir) {
    if(i >= n || arr[i] == -1) return 0;
    int next = dir == 0 ? 2*i+1 : 2*i+2;
    return 1 + zigzag(arr, next, n, 1-dir);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_z = 0;
    for(int i=0; i<n; i++) {
        int z1 = zigzag(arr, 2*i+1, n, 0);
        int z2 = zigzag(arr, 2*i+2, n, 1);
        int z = 1 + (z1 > z2 ? z1 : z2);
        if(z > max_z) max_z = z;
    }
    printf("%d\n", max_z);
    return 0;
}
