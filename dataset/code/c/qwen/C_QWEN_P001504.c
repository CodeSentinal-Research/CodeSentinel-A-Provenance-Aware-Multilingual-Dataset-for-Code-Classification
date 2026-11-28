#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, mask = 0;
    for(int r=0; r<n; r++) {
        while((mask & arr[r]) != 0) { mask ^= arr[l]; l++; }
        mask |= arr[r];
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
