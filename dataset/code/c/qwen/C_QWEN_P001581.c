#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, neg_count = 0;
    for(int r=0; r<n; r++) {
        if(arr[r] < 0) neg_count++;
        while(neg_count > k) { if(arr[l] < 0) neg_count--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
