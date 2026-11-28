/*
 * P001064: Check Whether an Edge Exists
 * Category: Graphs
 * Reads the input format described in the paired JSON problem file and prints the requested result.
 */
#include <stdio.h>
#include <stdlib.h>

static void solve_check_whether_an_edge_exists(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;
    unsigned char **adj = malloc((size_t)n * sizeof(unsigned char *));
    int *indeg = calloc((size_t)n, sizeof(int));
    int *outdeg = calloc((size_t)n, sizeof(int));
    for (int i = 0; i < n; ++i) adj[i] = calloc((size_t)n, 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n && !adj[u][v]) { adj[u][v] = 1; ++outdeg[u]; ++indeg[v]; }
    }
    int u, v;
    if (scanf("%d %d", &u, &v) != 2) return;
    printf("%s\n", u >= 0 && u < n && v >= 0 && v < n && adj[u][v] ? "YES" : "NO");
    for (int i = 0; i < n; ++i) free(adj[i]);
    free(adj);
    free(indeg);
    free(outdeg);
}

int main(void) {
    solve_check_whether_an_edge_exists();
    return 0;
}
