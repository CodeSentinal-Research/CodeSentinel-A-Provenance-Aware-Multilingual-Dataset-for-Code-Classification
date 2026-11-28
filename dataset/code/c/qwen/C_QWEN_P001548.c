#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    long long prod = 1, max_prod = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) prod *= arr[i];
    }
    max_prod = prod;
    for(int i=k; i<n; i++) {
        prod = prod / arr[i-k] * arr[i];
        if(prod > max_prod) max_prod = prod;
    }
    printf("%lld\n", max_prod);
    return 0;
}
