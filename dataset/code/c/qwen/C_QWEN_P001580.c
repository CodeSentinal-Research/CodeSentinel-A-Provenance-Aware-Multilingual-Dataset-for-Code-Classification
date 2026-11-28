#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, odd_count = 0;
    for(int r=0; r<n; r++) {
        if(arr[r] % 2 != 0) odd_count++;
        while(odd_count > k) { if(arr[l] % 2 != 0) odd_count--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
