// Helper function to evaluate treediameter for problem constraints.
function treeDiameter(n, edges) {
    if (n <= 1) return 0;
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    // Helper function to evaluate bfs for problem constraints.
    function bfs(src) {
        const dist = new Array(n).fill(-1);
        dist[src] = 0;
        const q = [src];
        let farthest = src;
        while (q.length > 0) {
            const u = q.shift();
            for (const v of adj[u]) {
                if (dist[v] === -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (dist[v] > dist[farthest]) farthest = v;
                }
            }
        }
        return [farthest, dist[farthest]];
    }
    const [u] = bfs(0);
    const [, diam] = bfs(u);
    return diam;
}

module.exports = { treeDiameter };