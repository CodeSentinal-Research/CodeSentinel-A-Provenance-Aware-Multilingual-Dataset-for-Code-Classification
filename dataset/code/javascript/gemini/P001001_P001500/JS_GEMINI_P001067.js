// Helper function to evaluate countreachable for problem constraints.
function countReachable(n, edges, src) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) adj[u].push(v);

    const vis = new Array(n).fill(false);
    const q = [src];
    vis[src] = true;
    let count = 0;

    while (q.length > 0) {
        const u = q.shift();
        count++;
        for (const v of adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return count;
}

module.exports = { countReachable };