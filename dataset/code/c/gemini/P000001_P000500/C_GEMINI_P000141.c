#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int **grid = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            grid[i] = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) scanf("%d", &grid[i][j]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) printf(" ");
                printf("%d", grid[n - 1 - j][i]);
            }
            printf("\n");
        }
        for (int i = 0; i < n; i++) free(grid[i]);
        free(grid);
    }
    return 0;
}