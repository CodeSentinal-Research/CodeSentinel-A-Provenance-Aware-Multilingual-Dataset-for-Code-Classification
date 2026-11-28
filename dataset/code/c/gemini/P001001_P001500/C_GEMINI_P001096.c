#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        long long cap[n][n];
        memset(cap, 0, sizeof(cap));
        int u_arr[m], v_arr[m];
        long long c_arr[m];
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lld", &u_arr[i], &v_arr[i], &c_arr[i]);
            cap[u_arr[i]][v_arr[i]] += c_arr[i];
        }
        int src, sink;
        scanf("%d %d", &src, &sink);

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
            int curr = sink;
            while (curr != src) {
                int p = parent[curr];
                cap[p][curr] -= aug;
                cap[curr][p] += aug;
                curr = p;
            }
        }

        bool vis[n];
        memset(vis, 0, sizeof(vis));
        vis[src] = true;
        int q[n];
        int head = 0, tail = 0;
        q[tail++] = src;
        while (head < tail) {
            int u = q[head++];
            for (int v = 0; v < n; v++) {
                if (!vis[v] && cap[u][v] > 0) {
                    vis[v] = true;
                    q[tail++] = v;
                }
            }
        }

        long long cut = 0;
        for (int i = 0; i < m; i++) {
            if (vis[u_arr[i]] && !vis[v_arr[i]]) cut += c_arr[i];
        }
        printf("%lld\n", cut);
    }
    return 0;
}