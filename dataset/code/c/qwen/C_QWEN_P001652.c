#include <stdio.h>

int lca(int *arr, int n, int p, int q) {
    int i = 0;
    while(i < n) {
        if(arr[i] > p && arr[i] > q) i = 2*i+1;
        else if(arr[i] < p && arr[i] < q) i = 2*i+2;
        else return arr[i];
    }
    return -1;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int p, q; scanf("%d %d", &p, &q);
    printf("%d\n", lca(arr, n, p, q));
    return 0;
}
