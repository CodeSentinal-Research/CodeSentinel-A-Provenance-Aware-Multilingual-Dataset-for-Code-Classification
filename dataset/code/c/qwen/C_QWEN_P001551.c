#include <stdio.h>
int main() {
    int n; long long k; scanf("%d %lld", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0;
    long long sum = 0;
    for(int r=0; r<n; r++) {
        sum += arr[r];
        while(sum > k) { sum -= arr[l]; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
