#include <stdio.h>
#include <limits.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    long long grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    long long max_sum = LLONG_MIN;
    for(int r1=0; r1<n; r1++) for(int r2=r1; r2<n; r2++) {
        long long min_pref = 0;
        for(int c=1; c<=m; c++) {
            long long sum = prefix[r2+1][c] - prefix[r1][c];
            if(sum - min_pref > max_sum) max_sum = sum - min_pref;
            if(sum < min_pref) min_pref = sum;
        }
    }
    printf("%lld\n", max_sum);
    return 0;
}
