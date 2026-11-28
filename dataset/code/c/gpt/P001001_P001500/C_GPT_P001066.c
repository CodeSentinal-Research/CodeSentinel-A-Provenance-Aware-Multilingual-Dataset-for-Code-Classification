/*
 * P001066: Find All Neighbors of a Vertex
 * Category: Graphs
 * Reads the input format described in the paired JSON problem file and prints the requested result.
 */
#include <stdio.h>
#include <stdlib.h>

static void solve_find_all_neighbors_of_a_vertex(void) {
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
    int u, first = 1;
    if (scanf("%d", &u) != 1) return;
    for (int v = 0; v < n; ++v) if (u >= 0 && u < n && adj[u][v]) { printf("%s%d", first ? "" : " ", v); first = 0; }
    printf("\n");
    for (int i = 0; i < n; ++i) free(adj[i]);
    free(adj);
    free(indeg);
    free(outdeg);
}

int main(void) {
    solve_find_all_neighbors_of_a_vertex();
    return 0;
}
