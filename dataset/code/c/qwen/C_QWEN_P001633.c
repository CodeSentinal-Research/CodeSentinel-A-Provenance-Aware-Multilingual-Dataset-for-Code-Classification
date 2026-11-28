#include <stdio.h>
#include <limits.h>

int main() {
    int n, m; long long k; scanf("%d %d %lld", &n, &m, &k);
    long long grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    long long max_area = 0;
    for(int r1=0; r1<n; r1++) for(int r2=r1; r2<n; r2++) {
        int l=1, r=m, ans=0;
        // Binary search on width for fixed height
        while(l<=r) {
            int mid = l+(r-l)/2;
            int ok = 0;
            for(int c=mid; c<=m; c++) {
                long long sum = prefix[r2+1][c] - prefix[r1][c] - prefix[r2+1][c-mid] + prefix[r1][c-mid];
                if(sum <= k) { ok = 1; break; }
            }
            if(ok) { ans = mid; l = mid+1; }
            else r = mid-1;
        }
        long long area = (long long)(r2-r1+1) * ans;
        if(area > max_area) max_area = area;
    }
    printf("%lld\n", max_area);
    return 0;
}
