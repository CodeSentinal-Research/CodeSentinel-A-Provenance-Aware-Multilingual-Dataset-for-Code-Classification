#include <stdio.h>
int main() {
    int n, x; scanf("%d %d", &n, &x);
    int arr[n];
    long long total = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); total += arr[i]; }
    if(total == x) { printf("%d\n", n); return 0; }
    int max_len = -1, l = 0;
    long long cur = 0, target = total - x;
    for(int r=0; r<n; r++) {
        cur += arr[r];
        while(cur > target && l <= r) { cur -= arr[l]; l++; }
        if(cur == target) {
            int len = n - (r - l + 1);
            if(len > max_len) max_len = len;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
