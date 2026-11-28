#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int max_ones = -1, idx = 0;
    for(int i=0; i<r; i++) {
        int ones = 0;
        for(int j=0; j<c; j++) if(mat[i][j] == 1) ones++;
        if(ones > max_ones) { max_ones = ones; idx = i; }
    }
    printf("%d\n", idx);
    return 0;
}
