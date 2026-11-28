#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        long long cap[n][n];
        memset(cap, 0, sizeof(cap));
        for (int i = 0; i < m; i++) {
            int u, v;
            long long c;
            scanf("%d %d %lld", &u, &v, &c);
            cap[u][v] += c;
        }
        int src, sink;
        scanf("%d %d", &src, &sink);
        long long flow = 0;

        while (1) {
            int parent[n];
            memset(parent, -1, sizeof(parent));
            parent[src] = -2;
            long long curCap[n];
            curCap[src] = LLONG_MAX;
            int q[n];
            int head = 0, tail = 0;
            q[tail++] = src;

            while (head < tail) {
                int u = q[head++];
                if (u == sink) break;
                for (int v = 0; v < n; v++) {
                    if (parent[v] == -1 && cap[u][v] > 0) {
                        parent[v] = u;
                        curCap[v] = curCap[u] < cap[u][v] ? curCap[u] : cap[u][v];
                        q[tail++] = v;
                    }
                }
            }
            if (parent[sink] == -1) break;
            long long aug = curCap[sink];
            flow += aug;
            int curr = sink;
            while (curr != src) {
                int p = parent[curr];
                cap[p][curr] -= aug;
                cap[curr][p] += aug;
                curr = p;
            }
        }
        printf("%lld\n", flow);
    }
    return 0;
}