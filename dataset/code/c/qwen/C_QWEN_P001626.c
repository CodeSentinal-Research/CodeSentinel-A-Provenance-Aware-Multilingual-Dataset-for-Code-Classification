#include <stdio.h>

int main() {
    int n, m; long long threshold; scanf("%d %d %lld", &n, &m, &threshold);
    long long grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    int max_side = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
        int l=1, r=(i<j?i:j), ans=0;
        while(l<=r) {
            int mid = l+(r-l)/2;
            long long sum = prefix[i][j] - prefix[i-mid][j] - prefix[i][j-mid] + prefix[i-mid][j-mid];
            if(sum <= threshold) { ans = mid; l = mid+1; }
            else r = mid-1;
        }
        if(ans > max_side) max_side = ans;
    }
    printf("%d\n", max_side);
    return 0;
}
