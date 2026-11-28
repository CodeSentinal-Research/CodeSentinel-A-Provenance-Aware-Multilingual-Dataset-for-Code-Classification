#include <stdio.h>
#define MAX_N 100005
int pref[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            pref[i + 1] = pref[i] + (x % 2 != 0 ? 1 : 0);
        }
        int q; scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d %d", &l, &r);
            printf("%d\n", pref[r + 1] - pref[l]);
        }
    }
    return 0;
}