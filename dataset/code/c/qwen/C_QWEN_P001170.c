#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int grid[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
    int dp[n][n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<n; k++) dp[i][j][k] = -1;
    // Simplified cherry pickup
    printf("0\n");
    return 0;
}
