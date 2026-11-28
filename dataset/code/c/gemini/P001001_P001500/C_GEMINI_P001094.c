#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool bpm(int u, int n, bool adj[][100], bool seen[], int matchR[]) {
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], n, adj, seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int m, n, k;
    if (scanf("%d %d %d", &m, &n, &k) == 3) {
        bool adj[100][100] = {false};
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = true;
        }
        int matchR[100];
        memset(matchR, -1, sizeof(matchR));
        int count = 0;
        for (int u = 0; u < m; u++) {
            bool seen[100] = {false};
            if (bpm(u, n, adj, seen, matchR)) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}