// Helper function to evaluate reachabilityqueries for problem constraints.
function reachabilityQueries(n, edges, queries) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) adj[u].push(v);

    const res = [];
    for (const [src, dst] of queries) {
        const vis = new Array(n).fill(false);
        vis[src] = true;
        const q = [src];
        let found = false;
        while (q.length > 0) {
            const u = q.shift();
            if (u === dst) { found = true; break; }
            for (const v of adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        res.push(found ? 'YES' : 'NO');
    }
    return res;
}

module.exports = { reachabilityQueries };