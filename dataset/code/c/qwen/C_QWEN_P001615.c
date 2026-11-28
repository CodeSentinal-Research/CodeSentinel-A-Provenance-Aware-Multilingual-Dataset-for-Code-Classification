#include <stdio.h>
#include <string.h>

#define HASH_SIZE 200003
int hk[HASH_SIZE], hv[HASH_SIZE];

void put(int k, int v) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    hk[i] = k; hv[i] += v;
}
int get(int k) {
    int i = (k % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while(hk[i] && hk[i] != k) i = (i + 1) % HASH_SIZE;
    return hk[i] == k ? hv[i] : 0;
}

int main() {
    int n, m, target; scanf("%d %d %d", &n, &m, &target);
    long long grid[n][m], prefix[n+1][m+1];
    for(int i=0; i<=n; i++) prefix[i][0] = 0;
    for(int j=0; j<=m; j++) prefix[0][j] = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        scanf("%lld", &grid[i][j]);
        prefix[i+1][j+1] = grid[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
    }
    int count = 0;
    for(int r1=0; r1<n; r1++) for(int r2=r1; r2<n; r2++) {
        memset(hk, 0, sizeof(hk)); memset(hv, 0, sizeof(hv));
        put(0, 1);
        for(int c=1; c<=m; c++) {
            int sum = prefix[r2+1][c] - prefix[r1][c];
            count += get(sum - target);
            put(sum, 1);
        }
    }
    printf("%d\n", count);
    return 0;
}
