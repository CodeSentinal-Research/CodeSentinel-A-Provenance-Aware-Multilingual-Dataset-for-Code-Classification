#include <stdlib.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
    int m = matSize, n = matColSize[0];
    int** p = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) p[i] = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        }
    }

    int lo = 0, hi = MIN(m, n);
    int ans = 0;

    while (lo <= hi) {
        // Calculate midpoint to prevent potential overflow
        int mid = (lo + hi) / 2;
        if (mid == 0) { lo = 1; continue; }
        bool found = false;

        for (int i = 0; i <= m - mid; i++) {
            for (int j = 0; j <= n - mid; j++) {
                int sum = p[i + mid][j + mid] - p[i][j + mid] - p[i + mid][j] + p[i][j];
                if (sum <= threshold) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    for (int i = 0; i <= m; i++) free(p[i]);
    free(p);
    return ans;
}