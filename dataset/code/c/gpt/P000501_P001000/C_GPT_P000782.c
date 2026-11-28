#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Count Elements in Range */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long pref[200001];
    pref[0] = 0;
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    if (strstr("Count Elements in Range", "Pivot") || strstr("Count Elements in Range", "Middle")) {
        for (int i = 0; i < n; i++) if (pref[i] == pref[n] - pref[i + 1]) { printf("%d\n", i); return 0; }
        printf("-1\n");
    } else if (strstr("Count Elements in Range", "Running") || strstr("Count Elements in Range", "Prefix Sum")) {
        for (int i = 1; i <= n; i++) printf("%lld%s", pref[i], i == n ? "\n" : " ");
    } else {
        int l, r;
        if (scanf("%d %d", &l, &r) != 2) { l = 0; r = n - 1; }
        if (l < 0) l = 0; if (r >= n) r = n - 1;
        printf("%lld\n", l <= r ? pref[r + 1] - pref[l] : 0);
    }


    return 0;
}
