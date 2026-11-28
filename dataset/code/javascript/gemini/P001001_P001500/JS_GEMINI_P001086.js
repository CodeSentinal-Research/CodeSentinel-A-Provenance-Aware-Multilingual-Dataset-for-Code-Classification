// Helper function to evaluate multisourcebfs for problem constraints.
function multiSourceBfs(n, edges, sources) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const dist = new Array(n).fill(-1);
    const q = [];
    for (const s of sources) {
        dist[s] = 0;
        q.push(s);
    }
    while (q.length > 0) {
        const u = q.shift();
        for (const v of adj[u]) {
            if (dist[v] === -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

module.exports = { multiSourceBfs };