#include <stdio.h>
#define MAX_N 100005
int h[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &h[i]);
        int l = 0, r = n - 1;
        int l_max = 0, r_max = 0;
        long long water = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                if (h[l] >= l_max) l_max = h[l];
                else water += l_max - h[l];
                l++;
            } else {
                if (h[r] >= r_max) r_max = h[r];
                else water += r_max - h[r];
                r--;
            }
        }
        printf("%lld\n", water);
    }
    return 0;
}