#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], dp[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        scanf("%d", &mat[i][j]);
        dp[i][j] = mat[i][j];
        if(i>0 && j>0) dp[i][j] += dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        else if(i>0) dp[i][j] += dp[i-1][j];
        else if(j>0) dp[i][j] += dp[i][j-1];
    }
    printf("%d\n", dp[r-1][c-1]);
    return 0;
}
