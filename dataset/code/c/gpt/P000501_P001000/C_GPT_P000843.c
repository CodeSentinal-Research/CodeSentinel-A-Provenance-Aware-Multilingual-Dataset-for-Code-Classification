#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Minimize the Maximum Pair Difference */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long key;
    if (scanf("%lld", &key) != 1) key = n ? a[0] : 0;
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == key) { ans = m; break; }
        if (a[m] < key) l = m + 1; else r = m - 1;
    }
    if (strstr("Minimize the Maximum Pair Difference", "Insert")) printf("%d\n", ans >= 0 ? ans : l);
    else if (strstr("Minimize the Maximum Pair Difference", "Square Root") || strstr("Minimize the Maximum Pair Difference", "Perfect Square")) {
        long long lo = 0, hi = key, root = 0;
        while (lo <= hi) { long long mid = (lo + hi) / 2; if (mid * mid <= key) { root = mid; lo = mid + 1; } else hi = mid - 1; }
        printf(strstr("Minimize the Maximum Pair Difference", "Perfect") ? "%s\n" : "%lld\n", strstr("Minimize the Maximum Pair Difference", "Perfect") ? (root * root == key ? "Yes" : "No") : "");
    } else {
        printf("%d\n", ans);
    }


    return 0;
}
