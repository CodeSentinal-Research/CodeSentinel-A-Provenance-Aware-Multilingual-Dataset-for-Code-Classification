#include <stdio.h>
#include <stdlib.h>
int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int **grid = (int **)malloc(r * sizeof(int *));
        for (int i = 0; i < r; i++) {
            grid[i] = (int *)malloc(c * sizeof(int));
            for (int j = 0; j < c; j++) scanf("%d", &grid[i][j]);
        }
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                if (i > 0) printf(" ");
                printf("%d", grid[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < r; i++) free(grid[i]);
        free(grid);
    }
    return 0;
}