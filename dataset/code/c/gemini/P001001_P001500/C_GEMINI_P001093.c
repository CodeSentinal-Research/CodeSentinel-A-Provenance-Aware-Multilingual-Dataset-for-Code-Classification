#include <stdio.h>
#include <stdbool.h>

bool permute(int idx, int n, int p[], bool used[], bool adj1[10][10], bool adj2[10][10]) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj1[i][j] != adj2[p[i]][p[j]]) return false;
            }
        }
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            p[idx] = i;
            if (permute(idx + 1, n, p, used, adj1, adj2)) return true;
            used[i] = false;
        }
    }
    return false;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        bool adj1[10][10] = {false};
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj1[u][v] = adj1[v][u] = true;
        }
        bool adj2[10][10] = {false};
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj2[u][v] = adj2[v][u] = true;
        }
        int p[10];
        bool used[10] = {false};
        printf("%s\n", permute(0, n, p, used, adj1, adj2) ? "YES" : "NO");
    }
    return 0;
}