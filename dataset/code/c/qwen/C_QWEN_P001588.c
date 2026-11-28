#include <stdio.h>
int atMostK(int *arr, int n, int k) {
    if(k < 0) return 0;
    long long count = 0;
    int l = 0, odd_count = 0;
    for(int r=0; r<n; r++) {
        if(arr[r] % 2 != 0) odd_count++;
        while(odd_count > k) { if(arr[l] % 2 != 0) odd_count--; l++; }
        count += r - l + 1;
    }
    return count;
}
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%lld\n", atMostK(arr, n, k) - atMostK(arr, n, k-1));
    return 0;
}
