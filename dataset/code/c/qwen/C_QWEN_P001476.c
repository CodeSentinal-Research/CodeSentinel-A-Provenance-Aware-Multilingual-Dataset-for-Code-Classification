#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    
    int l = 0, r = n - 1;
    int max_l = 0, max_r = 0;
    long long water = 0;
    while (l < r) {
        if (h[l] < h[r]) {
            if (h[l] > max_l) max_l = h[l];
            else water += max_l - h[l];
            l++;
        } else {
            if (h[r] > max_r) max_r = h[r];
            else water += max_r - h[r];
            r--;
        }
    }
    printf("%lld\n", water);
    return 0;
}
