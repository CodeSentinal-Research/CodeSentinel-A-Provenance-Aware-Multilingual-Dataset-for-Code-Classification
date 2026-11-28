#include <stdio.h>
int main() {
    int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t); s--; t--;
    int cap[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) cap[i][j] = 0;
    for(int i=0; i<m; i++) { int u, v, c; scanf("%d%d%d", &u, &v, &c); cap[u-1][v-1] += c; }
    int flow[n][n]; for(int i=0; i<n; i++) for(int j=0; j<n; j++) flow[i][j] = 0;
    int total_flow = 0;
    while(1) {
        int parent[n]; for(int i=0; i<n; i++) parent[i] = -1;
        int queue[n], front = 0, rear = 0;
        queue[rear++] = s; parent[s] = s;
        while(front < rear && parent[t] == -1) {
            int u = queue[front++];
            for(int v=0; v<n; v++) {
                if(parent[v] == -1 && cap[u][v] - flow[u][v] > 0) { parent[v] = u; queue[rear++] = v; }
            }
        }
        if(parent[t] == -1) break;
        int path_flow = 1000000000;
        for(int v=t; v!=s; v=parent[v]) { int u = parent[v]; if(cap[u][v] - flow[u][v] < path_flow) path_flow = cap[u][v] - flow[u][v]; }
        for(int v=t; v!=s; v=parent[v]) { int u = parent[v]; flow[u][v] += path_flow; flow[v][u] -= path_flow; }
        total_flow += path_flow;
    }
    printf("%d\n", total_flow);
    return 0;
}
