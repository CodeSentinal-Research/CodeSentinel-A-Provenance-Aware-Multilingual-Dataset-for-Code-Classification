/*
 * P001084: Hamiltonian Cycle
 * Category: Graphs
 * Reads the input format described in the paired JSON problem file and prints the requested result.
 */
#include <stdio.h>
#include <stdlib.h>

static void solve_hamiltonian_cycle(void) {
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
    int *state = calloc((size_t)n, sizeof(int));
    int changed = 1, removed = 0;
    while (changed) {
        changed = 0;
        for (int u = 0; u < n; ++u) if (!state[u] && outdeg[u] == 0) {
            state[u] = 1; ++removed; changed = 1;
            for (int v = 0; v < n; ++v) if (adj[v][u]) --outdeg[v];
        }
    }
    printf("%s\n", removed == n ? "NO" : "YES");
    free(state);
    for (int i = 0; i < n; ++i) free(adj[i]);
    free(adj);
    free(indeg);
    free(outdeg);
}

int main(void) {
    solve_hamiltonian_cycle();
    return 0;
}
