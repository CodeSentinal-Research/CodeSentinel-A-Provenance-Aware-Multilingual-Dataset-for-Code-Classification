#include "lip.h"
#include <stdlib.h>
#include <string.h>

static int dfs(const int* matrix, int m, int n, int i, int j, int* cache) {
    int idx = i * n + j;
    if (cache[idx] != 0)
        return cache[idx];

    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int best = 1;
    int cur = matrix[idx];

    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            int nidx = ni * n + nj;
            if (matrix[nidx] > cur) {
                int len = 1 + dfs(matrix, m, n, ni, nj, cache);
                if (len > best)
                    best = len;
            }
        }
    }

    cache[idx] = best;
    return best;
}

int longest_increasing_path(const int* matrix, int m, int n) {
    if (m <= 0 || n <= 0 || matrix == NULL)
        return 0;

    int total = m * n;
    int* cache = (int*)calloc(total, sizeof(int));
    if (!cache)
        return 0;

    int max_len = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int len = dfs(matrix, m, n, i, j, cache);
            if (len > max_len)
                max_len = len;
        }
    }

    free(cache);
    return max_len;
}