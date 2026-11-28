#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l = 0, count = 0;
    long long prod = 1;
    for(int r=0; r<n; r++) {
        prod *= arr[r];
        while(prod >= k && l <= r) { prod /= arr[l]; l++; }
        count += r - l + 1;
    }
    printf("%d\n", count);
    return 0;
}
