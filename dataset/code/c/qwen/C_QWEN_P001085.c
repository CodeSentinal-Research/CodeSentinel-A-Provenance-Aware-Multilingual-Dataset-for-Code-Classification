#include <stdio.h>
int main() {
    int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t); s--; t--;
    int adj[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = 0;
    int in_deg[n]; for(int i=0; i<n; i++) in_deg[i] = 0;
    for(int i=0; i<m; i++) { int u, v; scanf("%d%d", &u, &v); adj[u-1][v-1] = 1; in_deg[v-1]++; }
    long long dp[n]; for(int i=0; i<n; i++) dp[i] = 0;
    dp[s] = 1;
    int queue[n], front = 0, rear = 0;
    for(int i=0; i<n; i++) if(in_deg[i] == 0) queue[rear++] = i;
    while(front < rear) {
        int u = queue[front++];
        for(int v=0; v<n; v++) {
            if(adj[u][v]) {
                dp[v] += dp[u];
                in_deg[v]--;
                if(in_deg[v] == 0) queue[rear++] = v;
            }
        }
    }
    printf("%lld\n", dp[t]);
    return 0;
}
