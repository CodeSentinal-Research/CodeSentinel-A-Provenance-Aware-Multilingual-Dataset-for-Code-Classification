#include <stdio.h>
int main() {
    int r, c, k; scanf("%d %d %d", &r, &c, &k);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) printf("%d ", mat[i][(j - k % c + c) % c]);
        printf("\n");
    }
    return 0;
}
