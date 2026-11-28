#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &mat[i][j]);
    int max_sum = -1000000000;
    for(int i=0; i<=r-3; i++) for(int j=0; j<=c-3; j++) {
        int sum = 0;
        for(int x=0; x<3; x++) for(int y=0; y<3; y++) sum += mat[i+x][j+y];
        sum -= mat[i+1][j] + mat[i+1][j+2];
        if(sum > max_sum) max_sum = sum;
    }
    printf("%d\n", max_sum);
    return 0;
}
