#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int mat[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}