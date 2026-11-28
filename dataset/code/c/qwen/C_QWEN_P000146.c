#include <stdio.h>
int main() {
    int r, c; scanf("%d %d", &r, &c);
    int mat[r][c], dp[r][c];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) { scanf("%d", &mat[i][j]); dp[i][j] = mat[i][j]; }
    int max_size = 0;
    for(int i=1; i<r; i++) for(int j=1; j<c; j++) {
        if(mat[i][j] == 1) dp[i][j] = 1 + (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        dp[i][j] = dp[i][j] < dp[i-1][j-1] + 1 ? dp[i][j] : dp[i-1][j-1] + 1;
        if(dp[i][j] > max_size) max_size = dp[i][j];
    }
    printf("%d\n", max_size);
    return 0;
}
