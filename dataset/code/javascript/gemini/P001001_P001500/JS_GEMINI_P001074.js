// Helper function to evaluate dijkstra for problem constraints.
function dijkstra(n, edges, src) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        adj[u].push([v, w]);
        adj[v].push([u, w]);
    }
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    const vis = new Array(n).fill(false);

    for (let iter = 0; iter < n; iter++) {
        let u = -1;
        for (let i = 0; i < n; i++) {
            if (!vis[i] && (u === -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        if (u === -1 || dist[u] === Infinity) break;
        vis[u] = true;
        for (const [v, w] of adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist.map(d => d === Infinity ? -1 : d);
}

module.exports = { dijkstra };