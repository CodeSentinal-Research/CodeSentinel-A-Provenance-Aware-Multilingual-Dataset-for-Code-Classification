#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2 && r > 0 && c > 0) {
        int a[r][c], b[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) scanf("%d", &b[i][j]);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d%s", a[i][j] + b[i][j], (j == c - 1 ? "" : " "));
            }
            printf("\n");
        }
    }
    return 0;
}