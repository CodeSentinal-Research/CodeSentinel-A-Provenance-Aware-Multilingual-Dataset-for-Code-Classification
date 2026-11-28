#include <stdio.h>

long long sum(int *arr, int i, int n) {
    if(i >= n || arr[i] == -1) return 0;
    return arr[i] + sum(arr, 2*i+1, n) + sum(arr, 2*i+2, n);
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long total = sum(arr, 0, n);
    long long max_prod = 0;
    for(int i=0; i<n; i++) {
        long long s = sum(arr, i, n);
        long long prod = s * (total - s);
        if(prod > max_prod) max_prod = prod;
    }
    printf("%lld\n", max_prod);
    return 0;
}
