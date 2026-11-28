// Helper function to evaluate bellmanford for problem constraints.
function bellmanFord(n, edges, src) {
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;

    for (let iter = 0; iter < n - 1; iter++) {
        for (const [u, v, w] of edges) {
            if (dist[u] !== Infinity && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (const [u, v, w] of edges) {
        if (dist[u] !== Infinity && dist[u] + w < dist[v]) {
            return "NEGATIVE CYCLE";
        }
    }

    return dist.map(d => d === Infinity ? -1 : d);
}

module.exports = { bellmanFord };