#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, i;
        scanf("%d", &n);
        long long b[n];
        for (i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
        }

        int possible = 1;

        // Check if b is non-decreasing
        for (i = 1; i < n; i++) {
            if (b[i] < b[i - 1]) {
                possible = 0;
                break;
            }
        }

        if (!possible) {
            printf("NO\n");
            continue;
        }

        // Find minimum element in b
        long long min_b = b[0];
        for (i = 1; i < n; i++) {
            if (b[i] < min_b) {
                min_b = b[i];
            }
        }

        // Check last difference condition
        if (n == 1) {
            // Single element always possible
            printf("YES\n");
            continue;
        }

        long long last_diff = b[n - 1] - b[n - 2];

        if (last_diff > min_b) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}

   
