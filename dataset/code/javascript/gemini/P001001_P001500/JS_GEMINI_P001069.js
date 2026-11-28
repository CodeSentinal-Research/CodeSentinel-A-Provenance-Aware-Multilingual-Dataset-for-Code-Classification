// Helper function to evaluate shortestpathdag for problem constraints.
function shortestPathDag(n, edges, src) {
    const adj = Array.from({ length: n }, () => []);
    const inDeg = new Array(n).fill(0);
    for (const [u, v, w] of edges) {
        adj[u].push([v, w]);
        inDeg[v]++;
    }
    const q = [];
    for (let i = 0; i < n; i++) {
        if (inDeg[i] === 0) q.push(i);
    }
    const order = [];
    while (q.length > 0) {
        const u = q.shift();
        order.push(u);
        for (const [v, w] of adj[u]) {
            if (--inDeg[v] === 0) q.push(v);
        }
    }
    const dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    for (const u of order) {
        if (dist[u] !== Infinity) {
            for (const [v, w] of adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    return dist.map(d => d === Infinity ? -1 : d);
}

module.exports = { shortestPathDag };