#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* seen = (int*)calloc(n + 2, sizeof(int));
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x >= 1 && x <= n + 1) seen[x] = 1;
        }

        int ans = 1;
        while (ans <= n + 1 && seen[ans]) ans++;
        printf("%d\n", ans);
        free(seen);
    }
    return 0;
}