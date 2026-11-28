// Helper function to evaluate istree for problem constraints.
function isTree(n, edges) {
    if (edges.length !== n - 1) return false;
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const vis = new Array(n).fill(false);
    // Helper function to evaluate dfs for problem constraints.
    function dfs(u) {
        vis[u] = true;
        for (const v of adj[u]) {
            if (!vis[v]) dfs(v);
        }
    }
    dfs(0);
    return vis.every(Boolean);
}

module.exports = { isTree };