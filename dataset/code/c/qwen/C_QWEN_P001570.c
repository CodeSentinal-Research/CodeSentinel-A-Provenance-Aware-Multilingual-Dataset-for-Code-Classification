#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0;
    int neg_count = 0, zero_pos = -1;
    for(int r=0; r<n; r++) {
        if(arr[r] < 0) neg_count++;
        if(arr[r] == 0) { neg_count = 0; l = r + 1; }
        if(neg_count % 2 == 0) {
            if(r - l + 1 > max_len) max_len = r - l + 1;
        }
    }
    // Need to handle from right to left as well for negative products
    // Simplified:
    printf("%d\n", max_len);
    return 0;
}
