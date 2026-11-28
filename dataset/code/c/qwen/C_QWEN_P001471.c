#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int h[n];
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    
    int l = 0, r = n - 1;
    long long max_area = 0;
    while (l < r) {
        long long area = (long long)(r - l) * (h[l] < h[r] ? h[l] : h[r]);
        if (area > max_area) max_area = area;
        if (h[l] < h[r]) l++;
        else r--;
    }
    printf("%lld\n", max_area);
    return 0;
}
