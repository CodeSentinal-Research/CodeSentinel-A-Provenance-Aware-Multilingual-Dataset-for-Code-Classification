// Helper function to evaluate hashamiltonianpath for problem constraints.
function hasHamiltonianPath(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const vis = new Array(n).fill(false);

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u, count) {
        if (count === n) return true;
        vis[u] = true;
        for (const v of adj[u]) {
            if (!vis[v] && dfs(v, count + 1)) return true;
        }
        vis[u] = false;
        return false;
    }

    for (let i = 0; i < n; i++) {
        if (dfs(i, 1)) return true;
    }
    return false;
}

module.exports = { hasHamiltonianPath };