#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int** mat = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            mat[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
        }

        long long ans = 0;
        int* rowDiff = (int*)malloc(m * sizeof(int));

        for (int l = 0; l < n; l++) {
            for (int i = 0; i < m; i++) rowDiff[i] = 0;
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) rowDiff[i] += (mat[i][r] == 1 ? 1 : -1);

                for (int i = 0; i < m; i++) {
                    int cur = 0;
                    for (int j = i; j < m; j++) {
                        cur += rowDiff[j];
                        if (cur == 0) ans++;
                    }
                }
            }
        }

        printf("%lld\n", ans);
        for (int i = 0; i < m; i++) free(mat[i]);
        free(mat);
        free(rowDiff);
    }
    return 0;
}