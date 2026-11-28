#include <stdio.h>
int main() {
    int n, l, s; scanf("%d%d", &n, &l);
    int board[n+1]; for(int i=0; i<=n; i++) board[i] = i;
    for(int i=0; i<l; i++) { int u, v; scanf("%d%d", &u, &v); board[u] = v; }
    scanf("%d", &s);
    for(int i=0; i<s; i++) { int u, v; scanf("%d%d", &u, &v); board[u] = v; }
    int dist[n+1], queue[n+1], front=0, rear=0;
    for(int i=0; i<=n; i++) dist[i] = -1;
    dist[1] = 0; queue[rear++] = 1;
    while(front < rear) {
        int u = queue[front++];
        for(int i=1; i<=6; i++) {
            int v = u + i;
            if(v <= n) {
                v = board[v];
                if(dist[v] == -1) { dist[v] = dist[u] + 1; queue[rear++] = v; }
            }
        }
    }
    printf("%d\n", dist[n]);
    return 0;
}
