#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int m;
        if (scanf("%d", &m) == 1) {
            int b[m];
            for (int i = 0; i < m; i++) scanf("%d", &b[i]);
            if (n != m) {
                printf("NO\n");
                return 0;
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) { ok = false; break; }
            }
            printf("%s\n", ok ? "YES" : "NO");
        }
    }
    return 0;
}