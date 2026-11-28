/*
 * P001122: Eventual Safe States
 * Category: Graphs
 * Reads the input format described in the paired JSON problem file and prints the requested result.
 */
#include <stdio.h>
#include <stdlib.h>

static void solve_eventual_safe_states(void) {
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
    int start = 0;
    scanf("%d", &start);
    int *seen = calloc((size_t)n, sizeof(int));
    int *queue = malloc((size_t)n * sizeof(int));
    int head = 0, tail = 0;
    if (start >= 0 && start < n) { seen[start] = 1; queue[tail++] = start; }
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < n; ++v) if (adj[u][v] && !seen[v]) { seen[v] = 1; queue[tail++] = v; }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) count += seen[i];
    printf("%d\n", count);
    free(queue);
    free(seen);
    for (int i = 0; i < n; ++i) free(adj[i]);
    free(adj);
    free(indeg);
    free(outdeg);
}

int main(void) {
    solve_eventual_safe_states();
    return 0;
}
