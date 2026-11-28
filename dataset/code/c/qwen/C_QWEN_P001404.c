#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int grid[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
            
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int match = 1;
            for (int k = 0; k < n; k++) {
                if (grid[i][k] != grid[k][j]) {
                    match = 0;
                    break;
                }
            }
            if (match) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
