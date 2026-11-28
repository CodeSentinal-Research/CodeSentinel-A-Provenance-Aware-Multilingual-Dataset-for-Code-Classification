// Helper function to evaluate countatdistancek for problem constraints.
function countAtDistanceK(n, edges, src, k) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const dist = new Array(n).fill(-1);
    dist[src] = 0;
    const q = [src];

    while (q.length > 0) {
        const u = q.shift();
        for (const v of adj[u]) {
            if (dist[v] === -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist.filter(d => d === k).length;
}

module.exports = { countAtDistanceK };